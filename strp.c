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
    const char *tempHaystack;
    const char *tempNeedle;
    const char *needleStart = needle;
    assert(haystack != NULL);
    assert(needle != NULL);
    /* Return the haystack if the needle is empty */ 
    if (*needle == '\0')
        return (char *) haystack;

    while (*haystack != '\0') {
         /* If needle appears in haystack, return pointer to first 
        character of first occurrence of needle in haystack */
        if (*needle == '\0') {
            return (char *) haystack - Str_getLength(needleStart);
        }
        /* If the next character matches, increment the needle and 
        haystack pointers */
        else if (*haystack == *needle) {
                needle++;
                haystack++;
        }
        /* Otherwise, go back and see if there is a match */
        else {
            if (needle != needleStart) {                       
            tempNeedle = needle-1;
            tempHaystack = haystack;
            while (tempNeedle != needleStart) {
                /* Go through needle checking against each corresponding
                value in haystack. If there is a match, store the next
                value as the new needle index and continue checking from 
                there */
                if (*tempHaystack == *tempNeedle) {
                    needle = tempNeedle + 1;
                    tempNeedle--;
                    tempHaystack--;
                    while (tempNeedle != needleStart) {
                        if (*tempHaystack == *tempNeedle) {
                            tempNeedle--;
                            tempHaystack--;
                    }
                        else {
                            tempHaystack = haystack;
                            needle = needleStart;
                            tempNeedle--;
                            break;
                        }
                        
                        }
                                              }
                /* If no match, lower tempNeedleIndex value */
                else {
                    tempNeedle--;
                    needle = 0;
            }
            }
            /* If the first characters are also the same, keep the 
            needleIndex. Otherwise, set needleIndex to 0 */
            if (*tempHaystack != *tempNeedle) {
                needle = needleStart;
            }
            }
            /* Update haystack index */
            haystack++;
        }
        
    }
    
    /* Return the appropriate pointer if needle comes at the very end of
    haystack */
    if (*haystack == '\0' && *needle == '\0')
        return (char *) (haystack - Str_getLength(needleStart)); 

    
    return NULL;

    }
