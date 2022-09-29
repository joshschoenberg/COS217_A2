#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include "stddef.h"

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

char Str_copy(char pcDest[], const char pcSrc[]) {
    assert(pcDest != NULL);
    assert(pcSrc != NULL);
    size_t nextCharacter = 0;
    while (pcSrc[nextCharacter] != '\0') {
        pcDest[nextCharacter] = pcSrc[nextCharacter];
        nextCharacter++;    
        }  
    return pcDest;
}
