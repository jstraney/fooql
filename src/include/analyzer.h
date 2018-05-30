#define ANALYZER_MAX_TOKEN_BUFFER_SIZE 4000

// types of tokens
typedef const enum {
  null_token = 1, int_token, float_token, string_token, var_token,
  l_paren_token, r_paren_token, plus_token, minus_token, mult_token,
  forward_slash_token, start_comment, end_comment, line_comment,
  newline_token, semicolon_token
} TokenType;

int read_token(char *text);
