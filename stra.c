#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <assert.h>
#include "stddef.h"
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
    return pcDest;
}

char *Str_concat(char pcDest[], const char pcSrc[]) {
    /* size_t pcDest_length = Str_getLength(pcDest);
    size_t pcSrc_length = Str_getLength(pcSrc); */
    int i = 0;
    int j = 0;
    while (pcSrc[i] != '\0') {
        i++;
    }
    while (pcDest[j] != '\0') {
        pcDest[i] = pcSrc[j];
        j++;
        i++;
    }
    pcDest[j+1] = '\0';
    return pcDest;
}

int Str_compare(const char pc1[], const char pc2[]) {
    int i = 0;
    while (pc1[i] != '\0') {
        if (pc1[i] > pc2[i])
            return 1;
        else if (pc1[i] < pc2[i])
            return -1;
    }
    return 0;
}

char *Str_search(const char haystack[], const char needle[]) {
    int haystackIndex = 0;
    int needleIndex = 0;
    if (needle[needleIndex] == '\0')
        return haystack;
    while (haystack[haystackIndex] != '\0') {
         /* If needle appears in haystack, return pointer to first 
        character of first occurrence of needle in haystack */
        if (needle[needleIndex] == '\0') {
            return haystack[haystackIndex - Str_getLength(needle)];
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
