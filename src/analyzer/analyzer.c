////// LEXICAL ANALYZER //////
#ifndef ANALYZER_H
#include "analyzer.h"
#define ANALYZER_H
#endif

#ifndef CTYPE_H
#include <ctype.h>
#define CTYPE_H
#endif

#ifndef ERR_H 
#include "err.h"
#define  ERR_H
#endif

#ifndef STDLIB_H
#include <stdlib.h>
#define STDLIB_H
#endif

#ifndef STRING_H
#include <string.h>
#define STRING_H
#endif

// buffer for all the tokens in a single request
char * analyzer_token_buffer [ANALYZER_MAX_TOKEN_BUFFER_SIZE];

const char * reserved_words [] = {
  "select",
  "or",
  "delete",
  "update",
  "from",
  "on",
  "and",
  "group",
  "having",
  "order",
  "by",
  "insert",
  "create",
  "drop"
};

Token * analyzer_new_token (TokenType type, char * lexeme) {

  Token token = {type, lexeme};

  Token * this = calloc(1, sizeof(Token *));

  this = &token;

  return this;

}

void analyzer_free_token (Token *token) {

  free(token);

}

// attempts to read an identifier 
Token * analyzer_read_identifier (char * text) {

  // buffer for current token being analyzed 
  char *cbuffer = (char*)calloc(ANALYZER_MAX_TOKEN_LENGTH, sizeof(char));

  int text_len = sizeof(text) / sizeof(char);

  for (int i = 0; i < text_len; i++) {

    char c = *(text + i);

    // keep going until not an identifier
    if (isalpha(c) || isdigit(c) || c == '_')
      *(cbuffer + i) = c;

    else break;
   
  }

  // check if reserved word, determine TokenType

  //return token
  
  return NULL;

}

// attempts to read a number 
Token * analyzer_read_number (char * text) {

  // buffer for current token being analyzed 
  char *cbuffer = (char*)calloc(ANALYZER_MAX_TOKEN_LENGTH, sizeof(char));

  int text_len = sizeof(text) / sizeof(char);

  for (int i = 0; i < text_len; i++) {

    // read until not a number 

    char c = *(text + i);

    if (isdigit(c))
      *(cbuffer + i) = c;
  
    // todo. get decimals too (for floats)
    
    else break;
   
  }
  
  return NULL;

}

// reads the next character (used with ';','+','(' ',' etc.)
Token * analyzer_read_character (char * text, TokenType type) {

  // char *c = text;
  
  // copy next, single character into a string
  
  // create token from that

  return NULL;

}

// takes incoming text character by character and breaks it into lexemes, or
// instances of specific types of tokens
void analyzer_read_tokens(char * text) {

  int text_len = sizeof(text) / sizeof(char);

  Token * next_token = NULL;

  for (int i = 0; i < text_len - 1; i++) {

    char c = *(text + i);

    // now begins the fun part, put the text into identifiable tokens. 
    // is it a semicolon? an identifier? a number or string?
    if (isalpha(c)) {

      // try to read as identifier
      next_token = analyzer_read_identifier(text);

      // if not a token, throw error
      if (next_token == NULL)
        err_raise_exception(__FILE__, __LINE__, "unrecognized identifier");

    }
    else if (isdigit(c)) {

      // if not a number, throw error
      next_token = analyzer_read_number(text);

      // if next token is null, throw an error

    }
    else if (c == '(') {

    }
    else if (c == ')') {

    }
    else if (c == ',') {

    }
    else if (c == ';') {

    }
    else if (c == '"') {

    }
    else if (c == '\'') {

    }
    else if (c == '/') {

    }
    else if (c == '*') {

    }
    else if (c == '+') {

    }
    else if (c == '-') {

    }
    else if (c == '_') {

    }
    else {

      // raise exception
      err_raise_exception(__FILE__, __LINE__, "unexpected character %c", c);

    }

  } 

}

// flushes the analyzers token buffer
void analyzer_flush_buffer(char * text) {

  int buffer_len = sizeof(analyzer_token_buffer) / sizeof(char*);

  for (int i = 0; i < buffer_len; i++) {

    int str_len = sizeof(analyzer_token_buffer[i]) / sizeof(char);

    memset(analyzer_token_buffer[i], '\0', str_len);

  }

}
