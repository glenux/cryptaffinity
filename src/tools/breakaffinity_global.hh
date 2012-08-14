#ifndef _BREAKAFFINITY_GLOBAL_HH
#define _BREAKAFFINITY_GLOBAL_HH

#include <stdio.h>
#include <stdlib.h>

#include "cryptaffinity.hh"

#define COLOR_GREEN "\x1B[33m"
#define COLOR_NORMAL "\x1B[0m"


#ifndef pDEBUG
#define pDEBUG(x,...)   if (DEBUG){ \
                        printf("%s:%d/ %s",x,__LINE__,COLOR_GREEN); \
                        printf(__VA_ARGS__); \
                        printf("%s",COLOR_NORMAL); \
						}
#endif

#endif
