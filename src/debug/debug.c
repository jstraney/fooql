////// DEBUG //////
#ifndef STDARG_H
#include <stdarg.h>
#define STDARG_H
#endif

#ifndef STRING_H
#include <string.h>
#define STRING_H
#endif

#ifndef STDIO_H 
#include <stdio.h>
#define  STDIO_H
#endif

char * debug_verbose = "f";

int debug_set_verbose (char * verbose_option) {

  debug_verbose = verbose_option;

  return 1;

}

void debug_print (char * format_str, ...) {

  if (strncmp(debug_verbose, "t", 1) != 0)
    return;

  va_list args;

  va_start(args, format_str);
  vfprintf(stdout, format_str, args);
  va_end(args);

}
