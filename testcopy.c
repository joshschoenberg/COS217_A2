#include "str.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>


int main(void) {
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
        printf("%c", acDest1[i]);
        i++;
    }
    i = 0;
    printf("acDest2: ");
    while (acDest2[i] != '\0') {
        printf("%c", acDest2[i]);
        i++;
    }
}