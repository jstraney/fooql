////// SERVER //////
///////////////////////////////////////////////////////////////////////////////
// this will open a socket on a port, start an event loop, and then receive
// incoming TCP packets. those packets should then be sent to other parts of
// the program
#ifndef SERVER_H
#include "server.h"
#define SERVER_H
#endif

#ifndef STDLIB_H
#include <stdlib.h>
#define STDLIB_H
#endif

#ifndef STDIO_H 
#include <stdio.h>
#define STDIO_H 
#endif

#ifndef DEBUG_H 
#include <debug.h>
#define DEBUG_H 
#endif

#ifndef DYAD_H
#include "dyad.h"
#define DYAD_H
#endif

// server uses the dyad library to open up a server. used example code in
// verbatim from https://github.com/rxi/dyad
static void on_data (dyad_Event *e) {

  int received = dyad_getBytesReceived(e->stream);

  if (received != e->size) {

    // keep writing the data to the response
    dyad_write(e->stream, e->data, e->size);

    // return early
    return;

  }

  // log packets received in verbose mode
  debug_print("%d of %d bytes received\n", received, e->size);
  debug_print("%s\n", e->data);

  // get data from the stream
  // char * data = e->data;

  // pass that data to the lexical analyzer
   
  // now pass the lexemes to the parser (calls code generator)
  
  // now use machine code in virtual machine
  
  // get output from VM and send to client

  // close stream with client
  dyad_end(e->stream);

}

static void on_error(dyad_Event *e) {

  if (e->msg != NULL)
    debug_print("server error: %s\n", e->msg);

}

static void on_accept (dyad_Event *e) {

  dyad_addListener(e->remote, DYAD_EVENT_DATA, on_data, NULL); 

  dyad_writef(e->remote, "welcome to fooql\r\n");

}

int start_server (int port) {

  dyad_Stream *serv; 

  dyad_init();

  serv = dyad_newStream();

  dyad_addListener(serv, DYAD_EVENT_ERROR, on_error, NULL);
  dyad_addListener(serv, DYAD_EVENT_ACCEPT, on_accept, NULL);

  dyad_listen(serv, port);

  while (dyad_getStreamCount() > 0) {

    dyad_update();

  }

  dyad_shutdown();

  return 0;

}
