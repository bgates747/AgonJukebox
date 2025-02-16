/* szip.c                                                                   *
*                                                                           *
*  written by Michael Schindler michael@compressconsult.com                 *
*  1997,1998                                                                *
*  http://www.compressconsult.com/                                         */

static char vmayor=1, vminor=12;

#include <stdio.h>
#include <stdlib.h>
#ifndef unix
// #include <io.h>
#include <fcntl.h>
#endif
#include <string.h>
#include <ctype.h>
#include "port.h"
#include "sz_mod4.h"
#include "sz_srt.h"
#include "reorder.h"

#define BLOCK_SIZE (1 << SIZE_SHIFT)

static void usage()
{   fprintf(stderr,"szip %d.%d (c)1997-2000 Michael Schindler, szip@compressconsult.com\n",
        vmayor, vminor);
    fprintf(stderr,"homepage: http://www.compressconsult.com/szip/\n");
    fprintf(stderr,"usage: szip [options] [inputfile [outputfile]]\n");
    fprintf(stderr,"option           meaning              default   range\n");
    fprintf(stderr,"-d               decompress\n");
    // fprintf(stderr,"-b<blocksize>    blocksize in 100kB   -b17      1-41\n");
    fprintf(stderr,"-b<blocksize>    blocksize in 100kB   -b1      1-41\n"); // default block size to minimum for ESP32-friendly decompression
    fprintf(stderr,"-o<order>        order of context     -o6       0, 3-255\n");
    fprintf(stderr,"-r<recordsize>   recordsize           -r1       1-127\n");
    fprintf(stderr,"-i               incremental          -i\n");
    fprintf(stderr,"-v<level>        verbositylevel       -v0       0-255\n");
    fprintf(stderr,"options may be combined into one, like -r3i\n");
    exit(1);
}

static int readnum(char **s, int min, int max)
{	int j=0;
	while (isdigit(**s))
	{	j=10*j+**s-'0';
		*s += 1;
	}
	if (j<min || j>max)
		usage();
	return j;
}

/* parameter values */
// uint4 blocksize=1703936;
uint4 blocksize = 32768; // 32 KB = 0x8000, ESP32-friendly default
uint order=6, verbosity=0, compress=1;
unsigned char recordsize=1;

static void writeglobalheader()
{   /* write magic SZ\012\004 */
    putchar(0x53);
    putchar(0x5a);
    putchar(0x0a);
    putchar(0x04);
    putchar(vmayor); /* version mayor of first version using the format */
    putchar(vminor); /* version minor of first version using the format */
}


static void no_szip()
{   fprintf(stderr, "probably not an szip file; could be szip version prior to 1.10\n");
    exit(1);
}

static void readglobalheader()
{   int ch, vmay;
    ch = getchar();
    if (ch == EOF) return;
    if (ch == 0x42) {ungetc(ch, stdin); return;} /* maybe blockheader */
    if (ch != 0x53) no_szip();
    if (getchar() != 0x5a) no_szip();
    if (getchar() != 0x0a) no_szip();
    if (getchar() != 0x04) no_szip();
    vmay = getchar();
    if (vmay == EOF || vmay==0) no_szip();
    ch = getchar();
    if (ch == EOF) no_szip();
    if (vmay>vmayor || (vmay==vmayor && ch>vminor))
    {   fprintf(stderr, "This file is szip version %d.%d, this program is %d.%d.\n Please update\n",
        vmay, ch, vmayor, vminor);
        exit(1);
    }
    if (vmay==1 && ch==10)
    {   fprintf(stderr, "This file is szip version 1.10ALPHAi");
        fprintf(stderr, "A decoder is available at the website http://www.compressconsult.com");
        exit(1);
    }
}


static void writeuint3(uint4 x)
{   putchar((char)((x>>16)&0xff));
    putchar((char)((x>>8)&0xff));
    putchar((char)(x&0xff));
}


static uint4 readuint3()
{   uint4 x;
    x = getchar();
    x = x<<8 | getchar();
    x = x<<8 | getchar();
    return x;
}


static uint writeblockdir(uint4 buflen)
{   /* write magic */
    putchar(0x42);
    putchar(0x48);
    writeuint3(buflen);
    putchar(0);   /* FIXME: empty filename to indicate end of dir */
    return 6;
}


static uint readblockdir(uint4 *buflen)
{   int ch;
    ch = getchar();
    if (ch == EOF) {*buflen = 0; return 0;}
    if (ch == 0x53)
    {   ungetc(ch, stdin);
        readglobalheader();
        ch=getchar();
        if (ch == EOF) {*buflen = 0; return 0;}
    }
    if (ch != 0x42) no_szip();
    if (getchar() != 0x48) no_szip();
    *buflen = readuint3();
    if (getchar() != 0) no_szip();  /* FIXME: read until empty filename */
    return 6;
} 


static void writestorblock(uint dirsize, uint4 buflen, unsigned char *buffer)
{   unsigned char *end;
    if (verbosity&1) fprintf( stderr, "Storing %d bytes ...", buflen);
    putchar(0); /* 0 means stored block */
    end = buffer + buflen;
    while (buffer<end)
    {   putchar(*buffer);
        buffer++;
    }
    writeuint3(dirsize+4+buflen);
}


static void readstorblock(uint dirsize, uint4 buflen, unsigned char *buffer)
{   if (verbosity&1) fprintf( stderr, "Reading %d bytes ...", buflen);
    if (fread(buffer,1,buflen,stdin) != buflen)
    {   fprintf(stderr,"Error reading input\n"); exit(1);}
    if (fwrite(buffer,1,buflen,stdout) != buflen)
    {   fprintf(stderr,"Error writing output\n"); exit(1);}
    if (readuint3() != dirsize+3+buflen) no_szip();
}

   
static void writeszipblock(uint dirsize, uint4 buflen, unsigned char *buffer)
{   uint4 indexlast;
#ifndef MODELGLOBAL
    sz_model m;
#endif
    if (verbosity&1) fprintf( stderr, "Processing %d bytes ...", buflen);
    putchar(1); /* 1 means szip block */
    if ((recordsize&0x7f) != 1)
    {	unsigned char *tmp;
		tmp = (unsigned char*) malloc(buflen+order);
		if (tmp==NULL)
		{	fprintf(stderr, "memory allocation error\n");
			exit(1);
		}
		reorder(buffer,tmp,buflen,recordsize&0x7f);
        memcpy(buffer,tmp,buflen);
		free(tmp);
	}

    if (recordsize &0x80)
	{	unsigned char tmp = *buffer;
        uint4 i;
		for (i=1; i<buflen; i++)
		{	unsigned char tmp1 = buffer[i];
			buffer[i] = (0x100 + tmp1 - tmp) & 0xff;
			tmp = tmp1;
		}
	}

    if (order==4)
		sz_srt_o4(buffer,buflen,&indexlast);
	else if (order==0)
		sz_srt_BW(buffer,buflen,&indexlast);
	else
		sz_srt(buffer,buflen,&indexlast,order);

    if (verbosity&1) fprintf(stderr," coding ...");

    writeuint3(indexlast);
    putchar((char)(order&0xff));

    initmodel(&m, dirsize+5, &recordsize);
    /* FIXME: write recordsize with putchar with planned output */

  { unsigned char *end;
    end = buffer+buflen;
    *end = ~*(end-1); /* to make sure we end a run at end */
   {unsigned char ch, *begin;
    begin = buffer;
    ch = *(buffer++);
    while (*buffer==ch)
       buffer++;
    sz_encode(&m, ch, (uint4)(buffer-begin));
   }
    fixafterfirst(&m);
    while (buffer<end)
    {   unsigned char ch, *begin;
        begin = buffer;
        ch = *(buffer++);
        while (*buffer==ch)
            buffer++;
        sz_encode(&m, ch, (uint4)(buffer-begin));
    }
  }
    deletemodel(&m);
}


static void readszipblock(uint dirsize, uint4 buflen, unsigned char *buffer)
{   unsigned char *tmp;
    uint4 indexlast, charcount[ALPHABETSIZE], bytesleft;
#ifndef MODELGLOBAL
    sz_model m;
#endif
    if (verbosity&1) fprintf( stderr, "Decoding %d bytes ", buflen);
    indexlast = readuint3();
    order = getchar();

	memset(charcount, 0, ALPHABETSIZE*sizeof(uint4));
    initmodel(&m, -1, &recordsize);

    if (verbosity&1)
    {   if (order != 6)
            fprintf( stderr, "-o%d ",order);
        if ((recordsize & 0x7f) != 1)
            fprintf( stderr, "-r%d ",recordsize&0x7f);
        if (recordsize & 0x80)
            fprintf( stderr, "-i ");
        fprintf( stderr, "...");
    }

    tmp = buffer;
    bytesleft = buflen;
    {   uint4 runlength;
        uint ch;
        sz_decode(&m, &ch, &runlength);
        if (runlength>bytesleft)
        {	fprintf(stderr, "input file corrupt");
			exit(1);
		}
        bytesleft -= runlength;
        charcount[ch] += runlength;
        while (runlength)
        {   *(tmp++) = ch;
            runlength--;
        }
    }
    fixafterfirst(&m);
    while (bytesleft)
    {   uint4 runlength;
        uint ch;
        sz_decode(&m, &ch, &runlength);
        if (runlength>bytesleft)
        {	fprintf(stderr, "input file corrupt");
			exit(1);
		}
        bytesleft -= runlength;
        charcount[ch] += runlength;
        while (runlength)
        {   *(tmp++) = ch;
            runlength--;
        }
    }
    deletemodel(&m);

    if (verbosity&1) fprintf( stderr, " processing ...");

	if (recordsize == 1)
	{	if (order==0)
			sz_unsrt_BW(buffer, NULL, buflen, indexlast, charcount);
		else
			sz_unsrt(buffer, NULL, buflen, indexlast, charcount, order);
//fwrite(buffer,1,buflen,stdout);
    }
	else
	{	tmp = (unsigned char*) malloc(buflen);
		if (tmp==NULL)
		{	fprintf(stderr, "memory allocation failure");
			exit(1);
		}
		if (order==0)
			sz_unsrt_BW(buffer, tmp, buflen, indexlast, charcount);
		else
			sz_unsrt(buffer, tmp, buflen, indexlast, charcount, order);
		if (recordsize & 0x80)
		{	uint4 i;
            unsigned char c = *tmp;
			for (i=1; i<buflen; i++)
			{	c = (c+tmp[i])&0xff;
				tmp[i] = c;
			}
		}
		unreorder(tmp,buffer,buflen,recordsize&0x7f);
		free(tmp);

        bytesleft = fwrite(buffer,1,buflen,stdout);
        if (bytesleft != buflen)
		{	fprintf(stderr, "error writing output");
			exit(1);
		}
    }
}


static void compressit()
{
    unsigned char *inoutbuffer;

    /* Allocate enough space for one block plus 'order' extra bytes */
    inoutbuffer = (unsigned char*) malloc(blocksize + order + 1);
    if (inoutbuffer == NULL) {
        fprintf(stderr, "memory allocation error\n");
        exit(1);
    }

    /* Write the file-global header */
    writeglobalheader();

    while (1)
    {
        uint4 buflen;
        uint i;

        /* Read up to 'blocksize' bytes from stdin */
        buflen = fread((char *)inoutbuffer, 1, (size_t)blocksize, stdin);
        if (buflen == 0)  /* End of input? */
            break;

#if ALPHABETSIZE == 64
        /*
         * LOSSY step: Discard the top two bits of each byte,
         * so any 8-bit value is masked to [0..63].
         * This means inoutbuffer[i] = inoutbuffer[i] & 0x3F.
         */
        for (i = 0; i < buflen; i++) {
            inoutbuffer[i] &= 0x3F;
        }
#endif

        /* Write a small directory/header chunk with the block length */
        i = writeblockdir(buflen);

        /* If block is too small, just store it raw. Otherwise, compress. */
        if (buflen <= order || buflen <= 5)
            writestorblock(i, buflen, inoutbuffer);
        else
            writeszipblock(i, buflen, inoutbuffer);

        if (verbosity & 1)
            fprintf(stderr, " done\n");
    }

    free(inoutbuffer);
}

static void decompressit()
{
    unsigned char *inoutbuffer = NULL;

    /* Initially, we have no allocated block */
    blocksize = 0;

    /* Read the global file header (e.g., magic bytes) */
    readglobalheader();

    while (1)
    {
        uint4 blocklen;
        uint  dirsize;
        int   ch;

        /* Read directory info (block header) */
        dirsize = readblockdir(&blocklen);
        if (dirsize == 0)
            break;  /* no more blocks */

        /* Ensure our buffer is large enough for this block */
        if (blocklen > blocksize) {
            if (inoutbuffer != NULL)
                free(inoutbuffer);

            inoutbuffer = (unsigned char *)malloc(blocklen);
            blocksize   = blocklen;

            if (inoutbuffer == NULL) {
                fprintf(stderr, "memory allocation error\n");
                exit(1);
            }
        }

        /* Read which type of block it is (stored = 0, szip-compressed = 1, etc.) */
        ch = getchar();
        if (ch == 0) {
            /* Stored block -> read raw data into 'inoutbuffer' */
            readstorblock(dirsize + 1, blocklen, inoutbuffer);
        }
        else if (ch == 1) {
            /* Szip-compressed block -> decode into 'inoutbuffer' */
            readszipblock(dirsize + 1, blocklen, inoutbuffer);
        }
        else {
            no_szip();  /* unrecognized block type */
        }

        /* If we are using a 64-symbol “compressed” alphabet,
         * and we want to expand back to e.g. top-two-bits=1,
         * we can do something like:  inout[i] |= 0xC0;
         * This is lossy: we no longer know the original bits! 
         * We are simply forcing them to 1 1.
         */
#if ALPHABETSIZE == 64
        {
            uint i;
            for (i = 0; i < blocklen; i++) {
                /* Force the top two bits to 1, so [0..63] becomes [192..255] */
                inoutbuffer[i] |= 0xC0;
            }
        }
#endif

        /* Now write the (possibly bit-twiddled) data to stdout */
        if (fwrite(inoutbuffer, 1, blocklen, stdout) != blocklen) {
            fprintf(stderr, "Error writing output\n");
            exit(1);
        }

        if (verbosity & 1)
            fprintf(stderr, " done\n");
    }

    free(inoutbuffer);
}


int main( int argc, char *argv[] )
{	char *infilename=NULL, *outfilename=NULL;
    uint i;

    for (i=1; i<(unsigned)argc; i++)
	{	char *s=argv[i];
	    if (*s == '-')
		{	s++;
			while (*s)
				switch (*(s++))
				{	case 'o': {order = readnum(&s,0,255); 
								  if(order==1 || order==2) usage(); break;}
					case 'r': {recordsize = (recordsize & 0x80) | 
								  readnum(&s,1,255); break;}
					// case 'b': {blocksize = (100000*readnum(&s,1,41)+0x7fff) & 0x7fff8000L; break;}
                    case 'b': { // modification for ESP32-friendly block size
                        uint custom_size = readnum(&s, 1, 41) * 100000; // User-specified size in 100 KB units
                        if (custom_size < 32768) { // Ensure blocksize never goes below 32 KB
                            custom_size = 32768;
                        }
                        blocksize = (custom_size + 0x7fff) & 0x7FFF8000L; // Align to 32 KB boundary
                        break;
                    } // end modification for ESP32-friendly block size
					case 'i': {recordsize |= 0x80; break;}
                    case 'v': {verbosity = readnum(&s,0,255); break;}
                    case 'd': {compress = 0; break;}
					default: usage();
				}
		} else if (infilename == NULL)
			infilename = s;
		else if (outfilename == NULL)
			outfilename = s;
		else
			usage();
	}

	if (verbosity) fprintf( stderr, "szip Version %d.%d on ", vmayor, vminor);

    if ( infilename == NULL )
    {   if (verbosity) fprintf( stderr, "stdin" );}
	else
	{	freopen( infilename, "rb", stdin );
        if (verbosity) fprintf( stderr, "%s", infilename );
    }
    if ( outfilename == NULL )
    {   if (verbosity) fprintf( stderr, " to stdout\n" );}
	else
	{	freopen( outfilename, "wb", stdout );
        if (verbosity) fprintf( stderr, " to %s\n", outfilename );
    }

#ifndef unix
    setmode( fileno( stdin ), O_BINARY );
    setmode( fileno( stdout ), O_BINARY );
#endif

    if (compress)
        compressit();
    else
        decompressit();

	return 0;
}
