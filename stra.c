#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <assert.h>
#include <stddef.h>
#include "str.h"

/* Given a char array, a string, returns the length of that string (as
a size_t) */
size_t Str_getLength(const char pcSrc[])
{
   size_t uLength = 0;
   assert(pcSrc != NULL);
   while (pcSrc[uLength] != '\0')
      uLength++;
   return uLength;
}
/* Returning a pointer to pcDest */
char *Str_copy(char pcDest[], const char pcSrc[]) {
    size_t nextCharacter = 0;
    assert(pcDest != NULL);
    assert(pcSrc != NULL);
    while (pcSrc[nextCharacter] != '\0') {
        pcDest[nextCharacter] = pcSrc[nextCharacter];
        nextCharacter++;    
        }  
    pcDest[nextCharacter] = '\0';
    return pcDest;
}

char *Str_concat(char pcDest[], const char pcSrc[]) {
    /* size_t pcDest_length = Str_getLength(pcDest);
    size_t pcSrc_length = Str_getLength(pcSrc); */
    int i = 0;
    int j = 0;
    assert(pcDest != NULL);
    assert(pcSrc != NULL);

    while (pcDest[i] != '\0') {
        i++;
    }
    while (pcSrc[j] != '\0') {
        pcDest[i] = pcSrc[j];
        j++;
        i++;
    }
    pcDest[i] = '\0';
    return pcDest;
}

int Str_compare(const char pc1[], const char pc2[]) {
    int i = 0;
    assert(pc1 != NULL);
    assert(pc2 != NULL);
    while (pc1[i] != '\0' && pc2[i] != '\0') {
        if (pc1[i] > pc2[i])
            return 1;
        else if (pc1[i] < pc2[i])
            return -1;
        else 
            i++;
    } 
    /* Return 1 i pc1[] is longer than pc2[] */
    if (pc1[i] != '\0')
        return 1;
    /* Return -1 if pc1[] is shorter than pc2[] */
    if (pc2[i] != '\0')
        return -1;
    /* If they are equivalent in length, then return 0 */
    return 0;
}

char *Str_search(const char haystack[], const char needle[]) {
    size_t haystackIndex;
    size_t needleIndex;
    assert(haystack != NULL);
    haystackIndex = 0;
    needleIndex = 0;
    if (needle[needleIndex] == '\0')
        return (char *) haystack;
    while (haystack[haystackIndex] != '\0') {
         /* If needle appears in haystack, return pointer to first 
        character of first occurrence of needle in haystack */
        if (needle[needleIndex] == '\0') {
            return (char *) (haystack + haystackIndex - Str_getLength(needle));
        }
        else if (haystack[haystackIndex] == needle[needleIndex]) {
                needleIndex++;
                haystackIndex++;
        }
        else {
            needleIndex = 0;
            haystackIndex++;
        }
    }
    return NULL;
}
