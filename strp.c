#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <assert.h>
#include "str.h"

size_t Str_getLength(const char *pcSrc) {
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
    while (*pcSrc != '\0')  {
        *pcDest = *pcSrc;
        pcDest++;
        pcSrc++;
    }
    *pcDest = '\0';
return pcDestStart;
}


char *Str_concat(char *pcDest, const char *pcSrc) {
    char *pcDestStart = pcDest;
    while (*pcDest != '\0')
        pcDest++;
    while (*pcSrc != '\0') {
        *pcDest = *pcSrc;
        pcDest++;
        pcSrc++;
    }
    pcDest = '\0';
    return pcDestStart;
}

int Str_compare(const char *pc1, const char *pc2) {
    return 0;
}



/* 
char *Str_search(const char *haystack, const char *needle) {
    char *ptr = haystack;
    return ptr;
}
*/ 
char *Str_search(const char haystack[], const char needle[]) {
    size_t haystackIndex;
    size_t needleIndex;
    assert(haystack != NULL);
    assert(needle != NULL);
    haystackIndex = 0;
    needleIndex = 0;
    /* Return the haystack if the needle is empty */ 
    if (needle[needleIndex] == '\0')
        return (char *) haystack;
    while (haystack[haystackIndex] != '\0') {
         /* If needle appears in haystack, return pointer to first 
        character of first occurrence of needle in haystack */
        if (needle[needleIndex] == '\0') {
            return (char *) (haystack + haystackIndex - Str_getLength(needle));
        }
        /* If the next character matches, increment the needle and 
        haystack indices */
        else if (haystack[haystackIndex] == needle[needleIndex]) {
                needleIndex++;
                haystackIndex++;
        }
        /* If haystack character is the first letter of needle, go to 
        the second character of each */
        else if (haystack[haystackIndex] == *needle) {
            haystackIndex++;
            needleIndex += 1; /* Needle index becomes the second one */
        }
        else {
            needleIndex = 0;
            haystackIndex++;
        }
    }
    return NULL;
}
