#ifndef ERROR_H
#include "err.h"
#define ERROR_H
#endif

#ifndef STDIO_H 
#include <stdio.h> 
#define STDIO_H 
#endif

#ifndef STDLIB_H 
#include <stdlib.h> 
#define STDLIB_H 
#endif

#ifndef STDARG_H
#include <stdarg.h> 
#define STDARG_H
#endif

// borrowed from this stack overflow post:
// https://bit.ly/2J0p8pW
void raise_exception(char *filename, int line, char *format_str, ...) {

  va_list args; 

  fprintf(stderr, "Exception in '%s' : %d\n", filename, line);

  va_start(args, format_str);
  vfprintf(stderr, format_str, args);
  va_end(args);

  exit(EXIT_FAILURE);

}
