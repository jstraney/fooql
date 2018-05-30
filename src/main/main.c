#ifndef STDIO_H
#include <stdio.h>
#define STDIO_H
#endif

#ifndef STDLIB_H 
#include <stdlib.h>
#define STDLIB_H 
#endif

#ifndef STRING_H
#include <string.h>
#define STRING_H
#endif

#ifndef MAIN_H
#include "main.h"
#define MAIN_H
#endif

#ifndef DEBUG_H
#include "debug.h"
#define DEBUG_H
#endif

///////////////////////////////////////////////////////////////////////////////
// this will start up the database server. it's a c requirement to have a main
// function for your program. you may pass in a count of arguments, as well as
// the string arguments into the main function. In this case, the program is
// fooql, so running 'fooql bar' from the command line will pass 'bar' in
// as arg2 (arg1 is always the name of the command) 
int main (int argc, char* argv []) {

  // enumerated options available
  enum {
    FOOQL_PORT = 0,
    FOOQL_DIR,
    FOOQL_VERBOSE,
  };

  // total number of options (last minus first == total)
  const size_t FOOQL_NUM_OPTIONS = FOOQL_VERBOSE - FOOQL_PORT; 

  // actual options passed from command line 
  const char * fooql_options [FOOQL_NUM_OPTIONS + 1]; 

  // set defaults
  fooql_options[FOOQL_PORT] = "5446";
  fooql_options[FOOQL_DIR]  = "/usr/local/var";
  fooql_options[FOOQL_VERBOSE] = "f";

  /////////////////////////////////////////////////////////////////////////////
  // we should take the arguments for run-time options (yet to be determined)
  // these options then get passed to other parts of the program

  // I'm thinking:
  // -p to specify an application port (with some default)
  // -d for the database directory
  // -v for verbose logging
  // just some ideas
  for (int i =0; i < argc - 1; i++) {

    const char * flag = argv[i];

    if (strncmp("-p", flag, 2) == 0) {

      const char * port = argv[i + 1];

      fooql_options[FOOQL_PORT] = port;

    }
    else if (strncmp("-d", flag, 2) == 0) {

      const char * dir = argv[i + 1];

      fooql_options[FOOQL_DIR] = dir;

    }
    else if (strncmp("-v", flag, 2) == 0) {

      const char * verbose = argv[i + 1];

      fooql_options[FOOQL_VERBOSE] = verbose;

      debug_set_verbose(verbose);

    }

  }

  // now this will only print in debug mode (pass -v t ) with ./fooql
  debug_print("port, dir and verbose setttings:\n %s\n %s\n %s\n",
    fooql_options[FOOQL_PORT],
    fooql_options[FOOQL_DIR],
    fooql_options[FOOQL_VERBOSE]);

  /////////////////////////////////////////////////////////////////////////////
  // bootstrap the file where the database is stored (determined by configs)
  
  // something like this
  // set_up_db_file(<ARGS FROM CONFIG>);

  // FILE db = get_db_file(<ARGS FROM CONFIG>);

  /////////////////////////////////////////////////////////////////////////////
  // next step I think would be to instantiate the socket on the application
  // port. The port module should include the lexical analyzer, parser, and
  // virtual machine. so that It can pass off any text data packets to the
  // analyzer -> parser -> code_generator -> virtual_machine 
  
  // something like
  // open_port(<ARGS FROM CONFIG>);
  // ^ that should open an event loop

}
