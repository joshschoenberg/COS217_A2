/*--------------------------------------------------------------------*/
/* replace.c                                                          */
/* Author: Josh Schoenberg                                            */
/*--------------------------------------------------------------------*/

#include "str.h"
#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <string.h>

/*--------------------------------------------------------------------*/

/* If pcFrom is the empty string, then write string pcLine to stdout
   and return 0.  Otherwise write string pcLine to stdout with each
   distinct occurrence of string pcFrom replaced with string pcTo,
   and return a count of how many replacements were made.  Make no
   assumptions about the maximum number of replacements or the
   maximum number of characters in strings pcLine, pcFrom, or pcTo. */

static size_t replaceAndWrite(const char *pcLine,
                              const char *pcFrom, const char *pcTo)
{  
   /* Insert your code here. */
   size_t i;
   char *startReplace;
   char *previousStartReplace;
   size_t sizeOfFrom;
   /* size_t sizeOfTo; */
   size_t numberOfReplacements = 0;
   
   assert(pcLine != NULL);
   assert(pcFrom != NULL);
   assert(pcTo != NULL);

   /* If pcFrom is the empty string, then write string pcLine to stdout
   and return 0. */
   i = 0;
   if (*pcFrom == '\0') {
      while (pcLine[i] != '\0') {
         printf("%c", pcLine[i]);
         i++;
      }
      return 0;
   }
   
   /* Store the size of pcFrom and pcTo */
   sizeOfFrom = Str_getLength(pcFrom);
   /* sizeOfTo = Str_getLength(pcTo); */

   while (*pcLine != '\0') {
        
        /* Start of spot to replace: */
        startReplace = strstr(pcLine, pcFrom); /* or Str_search */
        if (startReplace != NULL && startReplace != 
                                                 previousStartReplace) {
        /* Print everything before the replace */
        while (pcLine != startReplace) {
          printf("%c", *pcLine);
          pcLine++;
        } 
        /* Print pcTo */
        i = 0;
        while (pcTo[i] != '\0') {
        printf("%c", pcTo[i]);
        i++;
        }
        /* Update previousStartReplace */
        previousStartReplace = startReplace;
        /* Move pcLine to the end of the replaced section */
        pcLine += sizeOfFrom;
        /* Increment numberOfReplacements */
        numberOfReplacements++;
   }
   }
    /* Print everything that's left */
    i = 0;
    while (pcLine[i] != '\0') {
        printf("%c", pcLine[i]);
        i++;
      }
    return numberOfReplacements;
}


/*--------------------------------------------------------------------*/

/* If argc is unequal to 3, then write an error message to stderr and
   return EXIT_FAILURE.  Otherwise...
   If argv[1] is the empty string, then write each line of stdin to
   stdout, write a message to stderr indicating that 0 replacements
   were made, and return 0.  Otherwise...
   Write each line of stdin to stdout with each distinct occurrence of
   argv[1] replaced with argv[2], write a message to stderr indicating
   how many replacements were made, and return 0.
   Assume that no line of stdin consists of more than MAX_LINE_SIZE-1
   characters. */

int main(int argc, char *argv[]) 
{
   enum {MAX_LINE_SIZE = 4096};
   enum {PROPER_ARG_COUNT = 3};

   char acLine[MAX_LINE_SIZE];
   char *pcFrom;
   char *pcTo;
   size_t uReplaceCount = 0;

   if (argc != PROPER_ARG_COUNT)
   {
      fprintf(stderr, "usage: %s fromstring tostring\n", argv[0]);
      return EXIT_FAILURE;
   }

   pcFrom = argv[1];
   pcTo = argv[2];

   while (fgets(acLine, MAX_LINE_SIZE, stdin) != NULL)
       /* Insert your code here. */
       uReplaceCount = replaceAndWrite(argv[0], pcFrom, pcTo);
    
    fprintf(stderr, "%lu replacements\n", (unsigned long)uReplaceCount);
   return 0;
}
