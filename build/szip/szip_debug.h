#ifndef SZIP_DEBUG_H
#define SZIP_DEBUG_H

#include <stdarg.h>
#include <stdio.h>
#include "port.h"

// Debug flag: Set to 1 to enable debug output, 0 to disable
#ifndef SZ_DEBUG
#define SZ_DEBUG 1
#endif

// Debug log function
static inline void szip_debug_log(const char *format, ...) {
    #if SZ_DEBUG == 1
    va_list ap;
    va_start(ap, format);
    flockfile(stderr);   // Thread-safe
    vfprintf(stderr, format, ap);
    fflush(stderr);
    funlockfile(stderr);
    va_end(ap);
    #endif
}

// Hex dump function
static inline void hex_dump(const unsigned char *buf, uint4 len) {
    #if SZ_DEBUG == 1
    uint4 i;
    flockfile(stderr);
    for (i = 0; i < len; i++) {
        fprintf(stderr, "%02X ", buf[i]);
        if ((i + 1) % 16 == 0) fprintf(stderr, "\n");
    }
    if (len % 16 != 0) fprintf(stderr, "\n");
    fflush(stderr);
    funlockfile(stderr);
    #endif
}

#endif  // SZIP_DEBUG_H
