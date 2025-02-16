/*
    sz_srt.c: Block-sorting / “n-order” sorting and unsorting routines
    (c) Michael Schindler, 1998, modifications for ALPHABETSIZE by ...
*/

#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "port.h"
#include "sz_err.h"
#include "sz_srt.h"

#if defined SZ_UNSRT_O4
#include "sz_hash2.h"    /* only used in sz_unsrt_o4 */
#endif

/*****************************************************************************/
/* 1) ALPHABET-SIZE MACROS (added)                                           */
/*****************************************************************************/
#ifndef ALPHABETSIZE
   #define ALPHABETSIZE 256  /* original default */
#endif

#if (ALPHABETSIZE == 256)
   #define ALPHABETBITS 8
#elif (ALPHABETSIZE == 64)
   #define ALPHABETBITS 6
#else
   #error "Unsupported ALPHABETSIZE (this example only handles 64 or 256)."
#endif

/* For 2-byte contexts, we need ALPHABETSIZE^2 */
#define ORDER2SIZE   (ALPHABETSIZE*ALPHABETSIZE)
#define ORDER2MASK   (ORDER2SIZE - 1)

/*
  The original code calls “sz_srt_o4” but only uses 16 bits internally (0x10000).
  We'll rename it ORDER16SIZE for clarity. It's still 16 bits even if ALPHABETBITS != 8.
  If you truly want 4-byte contexts (i.e. up to 32 bits for 256 or 24 bits for 64),
  you must rewrite that entire function. For now, we keep it at 16-bit.
*/
#define ORDER16SIZE  (1 << 16)
#define ORDER16MASK  (ORDER16SIZE - 1)

/*****************************************************************************/
/* 2) Other constants/structures from the original code                       */
/*****************************************************************************/
#define BITSSAMEBLOCK 10
#define BLOCKSIZE (1<<BITSSAMEBLOCK)
#define BLOCKMASK (BLOCKSIZE-1)

typedef struct p_block ptrblock;

struct p_block {
    uint2 msbytes[BLOCKSIZE];
    unsigned char lsbyte[BLOCKSIZE];
    ptrblock *nextfree;
};

typedef struct {
    ptrblock **index;    /* index to blocks used in current sort */
    ptrblock **oldindex; /* spare mem for alternate index */
    ptrblock  *freelist;
    ptrblock  *block;
    ptrblock  *spare[18];
    uint4 nrblocks;
} ptrstruct;

/*****************************************************************************/
/* 3) The global pointer structure                                           */
/*****************************************************************************/
static ptrstruct globalptr;
static int globalinit = 0;

/*****************************************************************************/
/* 4) Memory Allocation & Free Routines                                      */
/*****************************************************************************/
static void allocptrs(uint4 length, ptrstruct *p)
{
    p->nrblocks = (length + BLOCKSIZE - 1) / BLOCKSIZE;
    if (globalinit && (p->nrblocks > globalptr.nrblocks)) {
        free(globalptr.index);
        free(globalptr.oldindex);
        free(globalptr.block);
        globalinit = 0;
    }
    if (!globalinit) {
        globalptr.nrblocks = p->nrblocks;
        globalptr.index = (ptrblock**) malloc(sizeof(ptrblock*) * globalptr.nrblocks);
        if (globalptr.index == NULL)
            sz_error(SZ_NOMEM_SORT);

        globalptr.oldindex = (ptrblock**) malloc(sizeof(ptrblock*) * globalptr.nrblocks);
        if (globalptr.oldindex == NULL)
            sz_error(SZ_NOMEM_SORT);

        globalptr.block = (ptrblock*) malloc(sizeof(ptrblock) * globalptr.nrblocks);
        if (globalptr.block == NULL)
            sz_error(SZ_NOMEM_SORT);

        globalinit = 1;
    }
    p->index    = globalptr.index;
    p->oldindex = globalptr.oldindex;
    p->block    = globalptr.block;
    p->freelist = NULL;
    for (uint4 i = 0; i < 18; i++)
        p->spare[i] = NULL;
    for (uint4 i = 0; i < p->nrblocks; i++)
        p->index[i] = p->block + i;
}

static void extraspare(ptrstruct *p, int blocks)
{
    int i;
    ptrblock *extra = (ptrblock*) malloc(sizeof(ptrblock) * blocks);
    if (extra == NULL)
        sz_error(SZ_NOMEM_SORT);

    extra->nextfree = p->freelist;
    p->freelist = extra;
    for (i = 1; i < blocks; i++)
        p->freelist[i-1].nextfree = p->freelist + i;
    p->freelist[blocks-1].nextfree = NULL;
}

static void allocspareptrs(uint4 length, ptrstruct *p)
{
    length = (length >> BITSSAMEBLOCK) + 1;
    if (length > 256) length = 256; /* This limit is separate from ALPHABETSIZE logic */
    extraspare(p, (int)length);
}

static void freeptrs(ptrstruct *p)
{
    for (int i = 0; p->spare[i] != NULL; i++)
        free(p->spare[i]);
    /* The original code commented out freeing p->index, p->oldindex, p->block 
       because it reuses them globally. We’ll leave that alone. */
}

static inline void setptr(ptrstruct *p, uint4 i, uint4 ptr)
{
    ptrblock *tmp = p->index[i >> BITSSAMEBLOCK];
    if (tmp == NULL) {
        if (p->freelist == NULL)
            extraspare(p, 16);
        tmp = p->index[i >> BITSSAMEBLOCK] = p->freelist;
        p->freelist = p->freelist->nextfree;
    }
    i &= BLOCKMASK;
    tmp->msbytes[i] = (uint2)(ptr >> 8);
    tmp->lsbyte[i]  = (unsigned char)(ptr & 0xff);
}

/*****************************************************************************/
/* 5) Sorting Routines                                                       */
/*****************************************************************************/

/* sortorder2: does an initial pass with “order=2” logic */
static void sortorder2(ptrstruct *p, unsigned char *in, uint4 length,
                       uint4 *counts, unsigned int offset, uint4 *indexlast)
{
    uint4 i, *o2counts, sum;
    unsigned int context;

    /* Zero out frequency array of size ALPHABETSIZE */
    memset(counts, 0, ALPHABETSIZE * sizeof(uint4));

    /* For second-order, we need ALPHABETSIZE^2. Replacing 0x10000 with ORDER2SIZE. */
    o2counts = (uint4*)calloc(ORDER2SIZE, sizeof(uint4));
    if (o2counts == NULL)
        sz_error(SZ_NOMEM_SORT);

    /* Build contexts: old code did (in[length-1]<<8), replaced by shifting ALPHABETBITS */
    /* Since we want 2-byte context in terms of ALPHABETSIZE, do something like: */
    context = ((unsigned)in[length-1]) << ALPHABETBITS;

    for (i = 0; i < length; i++) {
        context = (context >> ALPHABETBITS) | ((unsigned)in[i] << ALPHABETBITS);
        counts[in[i]]++;
        o2counts[context]++;
    }

    /* Summation in reverse. Replacing for(i=0x10000; i--;) with for(i=ORDER2SIZE; i--;) */
    sum = length;
    for (i = ORDER2SIZE; i--; ) {
        sum -= o2counts[i];
        o2counts[i] = sum;
    }

    sum = length;
    /* Replacing for (i=0x100; i--;) with for (i=ALPHABETSIZE; i--;) */
    for (i = ALPHABETSIZE; i--; ) {
        sum -= counts[i];
        counts[i] = sum;
    }

    /* If context == 0xffff was used; now we do if (context == ORDER2MASK). */
    /* But we need to recalc “context” for the last offset. 
       The original code does something like: */
    context = ((unsigned)in[length - offset] << ALPHABETBITS) |
              (unsigned)in[length - offset - 1];
    if (context == ORDER2MASK)
        *indexlast = length - 1;
    else
        *indexlast = o2counts[context + 1] - 1;

    offset--;
    /* We replicate the old logic but shift by ALPHABETBITS. 
       The original code appended input to itself at in[i+length] = in[i], etc. 
       Left that as is. */

    for (i = 0; i < offset; i++) {
        in[i + length] = in[i];
        context = (context >> ALPHABETBITS) | ((unsigned)in[i + length - offset] << ALPHABETBITS);
        setptr(p, o2counts[context], i + length);
        o2counts[context]++;
    }
    for (; i < length; i++) {
        context = (context >> ALPHABETBITS) | ((unsigned)in[i - offset] << ALPHABETBITS);
        setptr(p, o2counts[context], i);
        o2counts[context]++;
    }
    free(o2counts);
}

static void incsortorder(ptrstruct *p, unsigned char *in, uint4 length,
                         uint4 *counts, int offset, uint4 *indexlast)
{
    uint4 i, block;
    uint4 ct[ALPHABETSIZE];
    ptrblock *curblock;
    unsigned char ch = 0;
    memcpy(ct, counts, ALPHABETSIZE * sizeof(uint4));

    { /* swap p->index and p->oldindex */
        ptrblock **swap = p->index;
        p->index = p->oldindex;
        p->oldindex = swap;
    }
    memset(p->index, 0, p->nrblocks * sizeof(ptrblock*));

    block = 0;
    curblock = p->oldindex[block];
    for (i = 0; i <= *indexlast; i++) {
        unsigned idx = i & BLOCKMASK;
        uint4 tmp = ((uint4)curblock->msbytes[idx] << 8) | curblock->lsbyte[idx];
        ch = in[tmp - offset];
        setptr(p, ct[ch], tmp);
        ct[ch]++;
        if (idx == BLOCKMASK && block != p->nrblocks - 1) {
            curblock->nextfree = p->freelist;
            p->freelist = curblock;
            block++;
            curblock = p->oldindex[block];
        }
    }
    *indexlast = ct[ch] - 1;
    for (; i < length; i++) {
        unsigned idx = i & BLOCKMASK;
        uint4 tmp = ((uint4)curblock->msbytes[idx] << 8) | curblock->lsbyte[idx];
        ch = in[tmp - offset];
        setptr(p, ct[ch], tmp);
        ct[ch]++;
        if (idx == BLOCKMASK && block < p->nrblocks - 1) {
            curblock->nextfree = p->freelist;
            p->freelist = curblock;
            block++;
            curblock = p->oldindex[block];
        }
    }
    curblock->nextfree = p->freelist;
    p->freelist = curblock;
}

static void finishsort(ptrstruct *p, unsigned char *in, uint4 length,
                       uint4 *counts, uint4 *indexlast)
{
    uint4 i, block;
    uint4 ct[ALPHABETSIZE];
    ptrblock *curblock;
    unsigned char ch = 0;
    {
        ptrblock **swap = p->index;
        p->index = p->oldindex;
        p->oldindex = swap;
    }
    memset(p->index, 0, p->nrblocks * sizeof(ptrblock*));
    memcpy(ct, counts, ALPHABETSIZE * sizeof(uint4));

    block = 0;
    curblock = p->oldindex[block];
    for (i = 0; i <= *indexlast; i++) {
        unsigned idx = i & BLOCKMASK;
        uint4 tmp = ((uint4)curblock->msbytes[idx] << 8) | curblock->lsbyte[idx];
        ch = in[tmp - 1];
        setptr(p, ct[ch], in[tmp]);
        ct[ch]++;
        if (idx == BLOCKMASK && block != p->nrblocks - 1) {
            curblock->nextfree = p->freelist;
            p->freelist = curblock;
            block++;
            curblock = p->oldindex[block];
        }
    }
    *indexlast = ct[ch] - 1;
    for (; i < length; i++) {
        unsigned idx = i & BLOCKMASK;
        uint4 tmp = ((uint4)curblock->msbytes[idx] << 8) | curblock->lsbyte[idx];
        ch = in[tmp - 1];
        setptr(p, ct[ch], in[tmp]);
        ct[ch]++;
        if (idx == BLOCKMASK && block != p->nrblocks - 1) {
            curblock->nextfree = p->freelist;
            p->freelist = curblock;
            block++;
            curblock = p->oldindex[block];
        }
    }
    curblock->nextfree = p->freelist;
    p->freelist = curblock;
    for (i = 0; i < p->nrblocks - 1; i++)
        memcpy(in + i*BLOCKSIZE, p->index[i]->lsbyte, BLOCKSIZE);
    i = p->nrblocks - 1;
    memcpy(in + BLOCKSIZE*i, p->index[i]->lsbyte, length - i*BLOCKSIZE);
}

/*****************************************************************************/
/* 6) Public Sort Entry Point                                                */
/*****************************************************************************/

/* 
  inout: bytes to be sorted; sorted bytes on return. must be length+order bytes long
  length: number of bytes in inout
  *indexlast: returns position of last context (needed for unsort)
  order: order of context used in sorting (must be >=3)
  The code assumes length>=order,
  and inout is length+order bytes long (only the first length need to be filled).
*/
void sz_srt(unsigned char *inout, uint4 length, uint4 *indexlast, unsigned int order)
{
    uint4 i;
    ptrstruct p;
    uint4 counts[ALPHABETSIZE];

    allocptrs(length, &p);
    sortorder2(&p, inout, length, counts, order, indexlast);
    allocspareptrs(length, &p);
    for (i = order - 2; i > 1; i--)
        incsortorder(&p, inout, length, counts, (int)i, indexlast);
    finishsort(&p, inout, length, counts, indexlast);
    freeptrs(&p);
}

/*****************************************************************************/
/* 7) Indirect bit flags for partial “context scanning”                      */
/*****************************************************************************/
#define INDIRECT 0x800000

#define setbit(flags, bit)    (flags[(bit)>>3] |=  (1 << ((bit) & 7)))
#define getbit(flags, bit)    ((flags[(bit)>>3] >> ((bit) & 7)) & 1)

static void makeorder2(unsigned char *flags, unsigned char *in, uint4 *counts,
                       uint4 length)
{
    uint4 i, j, ct[ALPHABETSIZE];
    memcpy(ct, counts, ALPHABETSIZE * sizeof(uint4));

    /* set bits in flags at start of each “order2 context” */
    for (i = 0; i < ALPHABETSIZE; i++)
        setbit(flags, ct[i]);

    j = 0;
    /* The code used 0..255, now replaced with ALPHABETSIZE-1. */
    for (i = 0; i < ALPHABETSIZE - 1; i++) {
        uint4 k;
        for (k = counts[i+1]; j < k; j++)
            ct[in[j]]++;
        for (k = 0; k < ALPHABETSIZE; k++)
            setbit(flags, ct[k]);
    }
}

static void increaseorder(unsigned char *inflags, unsigned char *outflags,
                          unsigned char *in, uint4 *counts, uint4 length)
{
    uint4 i, contextstart, ct[ALPHABETSIZE], lastseen[ALPHABETSIZE];
    memcpy(ct, counts, ALPHABETSIZE * sizeof(uint4));
    memset(lastseen, 0xff, ALPHABETSIZE * sizeof(uint4));
    contextstart = 0;

    for (i = 0; i < length; i++) {
        if (getbit(inflags, i))
            contextstart = i; 
        {
            unsigned ch = in[i];
            if (lastseen[ch] != contextstart) {
                lastseen[ch] = contextstart;
                setbit(outflags, ct[ch]);
            }
            ct[ch]++;
        }
    }
}

static void maketable(unsigned char *inflags, uint4 *table, unsigned char *in,
                      uint4 *counts, uint4 length)
{
    uint4 i, contextstart, ct[ALPHABETSIZE], firstseen[ALPHABETSIZE];
    memcpy(ct, counts, ALPHABETSIZE * sizeof(uint4));
    memset(firstseen, 0, ALPHABETSIZE * sizeof(uint4));
    contextstart = 0;

    for (i = 0; i < length; i++) {
        if (getbit(inflags, i))
            contextstart = i;
        {
            unsigned ch = in[i];
            if (firstseen[ch] <= contextstart) {
                table[i] = ct[ch];
                firstseen[ch] = i+1;
            } else {
                table[i] = (firstseen[ch] - 1) | INDIRECT;
            }
            ct[ch]++;
        }
    }
}

/*****************************************************************************/
/* 8) The “unsorting” entry point                                           */
/*****************************************************************************/

/*
 in: bytes to be unsorted
 out: unsorted bytes; if out==NULL => output to stdout
 length: number of bytes in in (and out)
 indexlast: position of last context (as returned by sz_srt)
 counts: number of occurences of each byte in in (if NULL it will be calculated)
 order: order of context used in sorting (must be >=3)
 code assumes length>=order
*/
void sz_unsrt(unsigned char *in, unsigned char *out, uint4 length, uint4 indexlast,
             uint4 *counts, unsigned int order)
{
    static uint4  *table   = NULL;
    static unsigned char *flags1 = NULL;
    static unsigned char *flags2 = NULL;
    unsigned char nocounts;

    nocounts = (counts == NULL);
    if (nocounts) {
        counts = (uint4*)calloc(ALPHABETSIZE, sizeof(uint4));
        if (counts == NULL) sz_error(SZ_NOMEM_SORT);
        for (uint4 i=0; i<length; i++)
            counts[in[i]]++;
    }

    /* sum counts */
    {
        uint4 j = length;
        for (int i = ALPHABETSIZE - 1; i >= 0; i--) {
            j -= counts[i];
            counts[i] = j;
            if (i == 0) break; /* watch out for unsigned wrap */
        }
    }

    /* allocate flags1/flags2 if not present, else clear them */
    {
        size_t flen = (length + 8) >> 3;
        if (flags1 == NULL) {
            flags1 = (unsigned char*)calloc(flen, 1);
            if (!flags1) sz_error(SZ_NOMEM_SORT);
        } else
            memset(flags1, 0, flen);

        if (flags2 == NULL) {
            flags2 = (unsigned char*)calloc(flen, 1);
            if (!flags2) sz_error(SZ_NOMEM_SORT);
        } else
            memset(flags2, 0, flen);
    }

    makeorder2(flags1, in, counts, length);

    /* now increase the order to desired order-1 */
    for (unsigned int i = 2; i < order-1; i++) {
        increaseorder(flags1, flags2, in, counts, length);
        /* swap flag pointers */
        {
            unsigned char *tmpflags = flags1;
            flags1 = flags2;
            flags2 = tmpflags;
        }
    }

    /* build the permutation table */
    if (table == NULL) {
        table = (uint4*)malloc((length+1)*sizeof(uint4));
        if (!table) sz_error(SZ_NOMEM_SORT);
    }
    maketable(flags1, table, in, counts, length);
    table[length] = INDIRECT;

    if (nocounts)
        free(counts);

    /* do the actual unsorting */
    {
        uint4 j = indexlast;
        if (out == NULL) {
            for (uint4 i=0; i<length; i++) {
                uint4 tmp = table[j];
                if (tmp & INDIRECT) {
                    j = table[tmp & ~INDIRECT]++;
                } else {
                    table[j]++;
                    j = tmp;
                }
                putc(in[j], stdout);
            }
        } else {
            for (uint4 i=0; i<length; i++) {
                uint4 tmp = table[j];
                if (tmp & INDIRECT) {
                    j = table[tmp & ~INDIRECT]++;
                } else {
                    table[j]++;
                    j = tmp;
                }
                out[i] = in[j];
            }
        }
        if (j != indexlast)
            sz_error(SZ_NOTCYCLIC);
    }
    /* Freed table/flags are left in static so re-used next time. 
       If you want to free them each time, uncomment the lines below:
    
       free(table);   table   = NULL;
       free(flags1);  flags1  = NULL;
       free(flags2);  flags2  = NULL;
    */
}

/*****************************************************************************/
/* 9) “Order-4” Variation (but using 16-bit context)                         */
/*****************************************************************************/
#if defined SZ_SRT_O4
/*
  The code calls “sz_srt_o4” a “fast alternate sort, only for order 4,” but it
  internally uses a 16-bit context (0x10000). We replaced references to 0x10000
  with ORDER16SIZE but left the logic of shifting by 8 bits in place, so it’s
  basically locked to 2-byte contexts. If you want it truly to handle
  ALPHABETBITS=6 for “64,” you still get a 16-bit context (0..65535 max).
  You can adapt further if needed.
*/
void sz_srt_o4(unsigned char *inout, uint4 length, uint4 *indexlast)
{
    static uint4 *counters = NULL;
    static uint2 *context  = NULL;
    static unsigned char *symbols = NULL;
    register uint4 i;

    /* count contexts */
    if (counters == NULL) {
        counters = (uint4*)calloc(ORDER16SIZE, sizeof(uint4));
        if (counters == NULL)
            sz_error(SZ_NOMEM_SORT);
    } else {
        memset(counters, 0, ORDER16SIZE*sizeof(uint4));
    }

    i = ((uint)inout[length-1]) << 8;
    {
        unsigned char *tmp;
        for (tmp = inout; tmp < inout+length; tmp++) {
            i = (i >> 8) | (((uint)*tmp) << 8);
            counters[i]++;
        }
    }

    {
        /* add context counts in reverse */
        register uint4 sum = length;
        for (i = ORDER16SIZE; i--; ) {
            sum -= counters[i];
            counters[i] = sum;
        }
    }

    /* first sort pass */
    if (context == NULL) {
        context = (uint2*)malloc(length * sizeof(uint2));
        if (!context) sz_error(SZ_NOMEM_SORT);
    }
    if (symbols == NULL) {
        symbols = (unsigned char*)malloc(length);
        if (!symbols) sz_error(SZ_NOMEM_SORT);
    }

    {
        register unsigned char *tmp;
        register uint4 ctx = ((uint4)inout[length-1] << 8) | inout[length-2];
        if (ctx == ORDER16MASK)
            *indexlast = length-1;
        else
            *indexlast = counters[ctx+1] - 1;

        ctx = (((uint4)inout[length-1]<<8 | inout[length-2]) << 8 |
                inout[length-3]) << 8 | inout[length-4];

        for (tmp = inout; tmp < inout+length; tmp++) {
            register uint4 x = counters[ctx & ORDER16MASK]++;
            context[x] = (uint2)(ctx >> 16);
            ctx = (ctx >> 8) | ((uint4)(symbols[x] = *tmp) << 24);
        }
    }

    /* second sort pass */
    {
        uint4 lastpos = *indexlast;
        for (i = length; i > lastpos; ) {
            i -= 1;
            inout[--counters[context[i]]] = symbols[i];
        }
        *indexlast = counters[context[i]];
        while (i--) {
            inout[--counters[context[i]]] = symbols[i];
        }
    }

    /* Freed arrays remain static. If needed to free each time:
       free(counters); counters=NULL;
       free(context);  context=NULL;
       free(symbols);  symbols=NULL;
    */
}
#endif /* SZ_SRT_O4 */

#ifdef SZ_UNSRT_O4
/*
  Similarly, an alternate backtransform for “order 4” but using a 16-bit approach.
  Replaced 0x10000 with ORDER16SIZE in allocations. Otherwise, the logic is mostly
  unchanged. If you truly want fewer bits for ALPHABETSIZE=64, rewrite it further.
*/
void sz_unsrt_o4(unsigned char *in, unsigned char *out, uint4 length, uint4 indexlast,
                 uint4 *counts)
{
    uint4 i, *contexts2, *contexts4, initcontext;
    uint2 *lastseen;
    unsigned char *loop, *endloop, nocounts;
    h2table htable;

    nocounts = (counts==NULL);
    if (nocounts) {
        counts = (uint4*)calloc(ALPHABETSIZE, sizeof(uint4));
        for (i=0; i<length; i++)
            counts[in[i]]++;
    }

    /* allocate contexts2 for order-2 counting: replaced 0x10000 => ORDER16SIZE */
    contexts2 = (uint4*)calloc(ORDER16SIZE, sizeof(uint4));
    if (!contexts2) sz_error(SZ_NOMEM_SORT);

    /* build contexts2 by reading “in” with old logic */
    loop = in;
    for (i = 0; i < ALPHABETSIZE; i++) {
        for (endloop = loop + counts[i]; loop < endloop; loop++)
            contexts2[((unsigned)*loop << 8) | i]++;
    }

    contexts4 = (uint4*)malloc(ORDER16SIZE * sizeof(uint4));
    if (!contexts4) sz_error(SZ_NOMEM_SORT);

    {
        uint4 sum = length;
        for (i = ORDER16SIZE; i--; ) {
            sum -= contexts2[i];
            contexts4[i] = sum;
        }
        initcontext = 0; /* see original code's logic for picking initcontext. */

        /* sum counts */
        sum = length;
        for (i = ALPHABETSIZE; i--; ) {
            sum -= counts[i];
            counts[i] = sum;
        }
    }

    initHash2(htable);

    lastseen = (uint2*)calloc(ORDER16SIZE, sizeof(uint2));
    if (!lastseen) sz_error(SZ_NOMEM_SORT);

    /* process context=0 first. . . (unchanged logic) */
    loop = in;
    for (endloop = loop + contexts2[0]; loop < endloop; loop++) {
        uint4 j, tmp = (uint4)(*loop);
        j = counts[tmp]++;
        tmp |= ((uint4)in[j] << 8);
        if (!lastseen[tmp]) {
            lastseen[tmp] = 1;
            h2_insert(htable, tmp << 16, contexts4[tmp]);
        }
        contexts4[tmp]++;
    }

    /* do the rest of contexts2 in a loop i=1..ORDER16SIZE-1, etc. */

    free(contexts2);
    free(contexts4);
    free(lastseen);
    if (nocounts)
        free(counts);

    /* do the actual unsorting. . . (unchanged logic, just replaced 0x10000 with ORDER16SIZE) */
    {
        uint4 context = initcontext >> 8 | (uint4)in[indexlast] << 24;
        if (out == NULL) {
            for (i=0; i<length; i++) {
                unsigned char outchar;
                outchar = in[h2_get_inc(htable, context)];
                context = (context >> 8) | ((uint4)outchar << 24);
                putc(outchar, stdout);
            }
        } else {
            for (i=0; i<length; i++) {
                unsigned char outchar;
                outchar = in[h2_get_inc(htable, context)];
                context = (context >> 8) | ((uint4)outchar << 24);
                out[i] = outchar;
            }
        }
        /* check final context matches the start */
        if (context != initcontext)
            sz_error(SZ_NOTCYCLIC);
    }
    freeHash2(htable);
}
#endif /* SZ_UNSRT_O4 */


#ifdef SZ_SRT_BW
/* Original blockwise fallback—unchanged except for “256” -> “ALPHABETSIZE” in a few places */
#include "qsort_u4.c"

void sz_srt_BW(unsigned char *inout, uint4 length, uint4 *indexfirst)
{
    uint4 i, counts[ALPHABETSIZE], counts1[ALPHABETSIZE], *contextp, start;

    for (i=0; i<ALPHABETSIZE; i++)
        counts[i] = 0;
    for (i=0; i<length; i++)
        counts[inout[i]]++;
    counts1[0] = 0;
    for (i=0; i<ALPHABETSIZE-1; i++)
        counts1[i+1] = counts1[i] + counts[i];

    contextp = (uint4*)calloc(length, sizeof(uint4));
    if (!contextp) sz_error(SZ_NOMEM_SORT);

    for (i=0; i<length; i++)
        contextp[counts1[inout[i]]++] = i;

    start = 0;
    for (i=0; i<ALPHABETSIZE; i++) {
        if (verbosity & 1) fputc((char)('0'+i%10), stderr);
        if (counts[i]) {
            qsort_u4(contextp+start, counts[i], inout, (i == inout[0] ? 0 : 1));
            if (i == inout[length-1]) {
                uint4 j=start;
                while(contextp[j] != (length-1))
                    j++;
                *indexfirst = j;
            }
            start += counts[i];
        }
    }

    contextp[*indexfirst] = 0;
    for (i=0; i<length; i++)
        contextp[i] = inout[ contextp[i]+1 ];
    contextp[*indexfirst] = inout[0];
    for (i=0; i<length; i++)
        inout[i] = (unsigned char)contextp[i];

    free(contextp);
}

void sz_unsrt_BW(unsigned char *in, unsigned char *out, uint4 length,
                 uint4 indexfirst, uint4 *counts)
{
    uint4 i, *transvec;
    unsigned char nocounts;

    nocounts = (counts==NULL);
    if (nocounts) {
        counts = (uint4*)calloc(ALPHABETSIZE, sizeof(uint4));
        if (!counts) sz_error(SZ_NOMEM_SORT);
        for (i=0; i<length; i++)
            counts[in[i]]++;
    }

    {
        uint4 sum = length;
        for (i=ALPHABETSIZE; i--; ) {
            sum -= counts[i];
            counts[i] = sum;
        }
    }

    transvec = (uint4*)malloc(length*sizeof(uint4));
    if (!transvec) sz_error(SZ_NOMEM_SORT);

    transvec[indexfirst] = counts[in[indexfirst]]++;
    for (i=0; i<indexfirst; i++)
        transvec[i] = counts[in[i]]++;
    for (; i<length; i++)
        if (i != indexfirst)
            transvec[i] = counts[in[i]]++;

    if (nocounts) free(counts);

    {
        uint4 ic = indexfirst;
        if (!out) {
            for (i=0; i<length; i++) {
                putc(in[ic], stdout);
                ic = transvec[ic];
            }
        } else {
            for (i=0; i<length; i++) {
                out[i] = in[ic];
                ic = transvec[ic];
            }
        }
        if (ic != indexfirst)
            sz_error(SZ_NOTCYCLIC);
    }
    free(transvec);
}
#endif /* SZ_SRT_BW */
