#ifndef _CRYPTAFINITY_GLOBAL_HH
#define _CRYPTAFINITY_GLOBAL_HH

#include <stdlib.h>
#include <stdio.h>
#include <list>
#include <vector>
#include <string>
#include <map>

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
