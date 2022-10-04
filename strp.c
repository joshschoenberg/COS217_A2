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
    assert(pcDest != NULL);
    assert(pcSrc != NULL);
    while (*pcDest != '\0')
        pcDest++;
    while (*pcSrc != '\0') {
        *pcDest = *pcSrc;
        pcDest++;
        pcSrc++;
    }
    *pcDest = '\0';
    return pcDestStart;
}

int Str_compare(const char *pc1, const char *pc2) {
    assert(pc1 != NULL);
    assert(pc2 != NULL);
    while (*pc1 != '\0' && *pc2 != '\0') {
        if (*pc1 > *pc2) 
            return 1;
        else if (*pc1 < *pc2) {
            return -1;
        }
        else {
            pc1++;
            pc2++;
        }
    } 
    /* Return 1 i pc1[] is longer than pc2[] */
    if (*pc1 != '\0')
        return 1;
    /* Return -1 if pc1[] is shorter than pc2[] */
    if (*pc2 != '\0')
        return -1;
    /* If they are equivalent in length, then return 0 */
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
