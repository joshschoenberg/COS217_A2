#ifndef STRA_INCLUDED
#define STRA_INCLUDED
#include <stddef.h>
/*--------------------------------------------------------------------*/

/* Return the length of String pcSrc */ 
size_t Str_getLength(const char pcSrc[]);

/*--------------------------------------------------------------------*/
/* Copy a string into a new string, and return that string */

char *Str_copy(char pcDest[], const char pcSrc[]);

/*--------------------------------------------------------------------*/

char *Str_concat(char pcDest[], const char pcSrc[]);


/*--------------------------------------------------------------------*/

int Str_compare(const char pc1[], const char pc2[]);


/*--------------------------------------------------------------------*/

char *Str_search(const char haystack[], const char needle[]);

#endif