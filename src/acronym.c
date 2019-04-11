#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "acronym.h"

static const int MAX_INPUT_STRING_LENGTH = 128;

// This exercise requires passing an array back
// Note that if we pass back a typical array back
// it won’t work because the array is allocated
// on the stack. We need it on the heap, so we use malloc() and rely on the caller to free() the array afterward.
char *abbreviate(const char *phrase)
{
  if(!phrase)
  {
    return NULL;
  }

  if(*phrase == '\0')
  {
    return NULL;
  }

  char *abbreviation = (char*) malloc(sizeof(char) * MAX_INPUT_STRING_LENGTH);
  memset(abbreviation, '\0', MAX_INPUT_STRING_LENGTH);

  // Tokenize string
  // Add every first letter and any lowercase
  char *phrase_token;
  const char *TOKEN_SEPARATORS = " -";
  char phrase_copy[MAX_INPUT_STRING_LENGTH];
  strncpy(phrase_copy, phrase, MAX_INPUT_STRING_LENGTH);

  phrase_token = strtok((char *)phrase_copy, TOKEN_SEPARATORS);

  while (phrase_token)
  {
    for (size_t i = 0; i < strnlen(phrase_token, MAX_INPUT_STRING_LENGTH); i++)
    {
      if (i == 0)
      {
        char letter = toupper(phrase_token[i]);
        strncat(abbreviation, &letter, 1);
      }
      // else if (isupper(phrase[i]))
      // {
      //   strncat(abbreviation, &phrase_token[i], 1);
      // }
    }

    phrase_token = strtok(NULL, TOKEN_SEPARATORS);
  }

  return abbreviation;
}
