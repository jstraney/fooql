////// LEXICAL ANALYZER //////
#ifndef ANALYZER_H
#include "analyzer.h"
#define ANALYZER_H
#endif

char * token_buffer [ANALYZER_MAX_TOKEN_BUFFER_SIZE];

// takes incoming text character by character and breaks it into lexemes, or
// instances of specific types of tokens
