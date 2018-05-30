#define ANALYZER_MAX_TOKEN_BUFFER_SIZE 4000
#define ANALYZER_MAX_TOKEN_LENGTH 64 

// types of tokens
typedef const enum {
  null_token = 1, int_token, float_token, string_token, var_token,
  l_paren_token, r_paren_token, plus_token, minus_token, mult_token,
  forward_slash_token, start_comment, end_comment, line_comment,
  newline_token, semicolon_token
} TokenType;

typedef struct {
  TokenType type;
  // a lexeme is the 'value' of the token, for instance, 
  // x and y are both identifiers, but their lexemes are
  // "x" and "y" respectively
  char * lexeme;
} Token;

Token * analyzer_new_token (TokenType type, char * lexeme);

void analyzer_free_token (Token *token);

void analyzer_read_tokens(char *text);

// flush the analyzer buffer
void analyzer_flush_buffer();
