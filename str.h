#ifndef STRA_INCLUDED
#define STRA_INCLUDED
#include <stddef.h>
/*--------------------------------------------------------------------*/

/* Return the length of String pcSrc */ 
size_t Str_getLength(const char pcSrc[]);

/*--------------------------------------------------------------------*/
/* Copy a string (pcSrc) into a new string (pcDest), and return a 
pointer to the new string */

char *Str_copy(char pcDest[], const char pcSrc[]);

/*--------------------------------------------------------------------*/
/* Add string (pcSrc) to end of other string (pcDest) and return pointer
to beginning of pcDest */

char *Str_concat(char pcDest[], const char pcSrc[]);

/*--------------------------------------------------------------------*/
/* Compares the two strings pc1 and pc2. It returns an integer less 
than, equal to, or greater than zero if  s1  is  found, respectively, to 
be less than, to match, or be greater than s2. */

int Str_compare(const char pc1[], const char pc2[]);

/*--------------------------------------------------------------------*/
/* Finds the first occurrence of the substring needle in the string 
haystack. Returns a pointer to that occurence */
char *Str_search(const char haystack[], const char needle[]);

#endif