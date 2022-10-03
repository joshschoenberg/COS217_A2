#include "str.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>

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

int main() {
    int i;
    char *pcResult;
    const char acSrc[] = {'\0', 's'};
    char acDest1[] = {'d', 'd'};
    char acDest2[] = {'d', 'd'};
    pcResult = Str_copy(acDest1, acSrc);
    (void)strcpy(acDest2, acSrc);
   
    i = 0;
    printf("acDest1: ");
    while (acDest1[i] != '\0') {
        printf(acDest1[i]);
        i++;
    }
    i = 0;
    printf("acDest2: ");
    while (acDest2[i] != '\0') {
        printf(acDest2[i]);
        i++;
    }
}