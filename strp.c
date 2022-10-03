#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <assert.h>
#include <stddef.h>
#include "str.h"

size_t Str_getLength(const char *pcSrc)
{
   const char *pcEnd;
   assert(pcSrc != NULL);
   pcEnd = pcSrc;
   while (*pcEnd != '\0')
      pcEnd++;
   return (size_t)(pcEnd - pcSrc);
}

char *Str_copy(char *pcDest, const char *pcSrc) { 
    char *pcDestStart = pcDest;
    assert(pcDest != NULL);
    assert(pcSrc != NULL);
    while (*pcSrc != '0')  {
        *pcDest = *pcSrc;
        pcDest++;
        pcSrc++;
    }
    *pcDest = '\0';
return pcDestStart;
}


char *Str_concat(char *pcDest, const char *pcSrc) {
    return pcDest;
}

int Str_compare(const char *pc1, const char *pc2) {
    return 0;
}




char *Str_search(const char *haystack, const char *needle) {
    return haystack;
}
