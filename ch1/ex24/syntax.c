#include <stdio.h>

#define MAXLINE 1000
#define MAXTOKENS 100

int mygetline(char s[], int m);

int main() {
  int c, i;
  char current[MAXLINE];
  char tokens[MAXTOKENS];
  int token_index = -1;
  int line_num = 0;
  int in_single_quotes = 0;
  int in_double_quotes = 0;
  int in_block_comment = 0;

  while (mygetline(current, MAXLINE) > 0) {
    ++line_num;

    // WALK DOWN THE LINE
    for (i = 0; (c = current[i]) != '\0'; ++i) {
      if (in_block_comment && c != '/')
        continue;
      else if (in_block_comment && c == '/' && 
               i > 0 && current[i - 1] == '*') {
        in_block_comment = 0;
        continue;
      }

      switch (c) {
        case '*':
          if (i > 0 && current[i - 1] == '/')
            in_block_comment = 1;
          break;

        case '\'':
          if (in_single_quotes)
            in_single_quotes = 0;
          else
            in_single_quotes = 1;
          break;

        case '\"':
          if (in_double_quotes)
            in_double_quotes = 0;
          else
            in_double_quotes = 1;
          break;

        case '{':
          ++token_index;
          tokens[token_index] = c;
          break;

        case '}':
          if (token_index == -1 || tokens[token_index] != '{') {
            printf("%s %d\n", "SyntaxError: Unexpected '}' on line", line_num);
            return 1;
          } else 
            --token_index;
          break;

        case '[':
          ++token_index;
          tokens[token_index] = c;
          break;

        case ']':
          if (token_index == -1 || tokens[token_index] != '[') {
            printf("%s %d\n", "SyntaxError: Unexpected ']' on line", line_num);
            return 1;
          } else 
            --token_index;
          break;

        case '(':
          ++token_index;
          tokens[token_index] = c;
          break;

        case ')':
          if (token_index == -1 || tokens[token_index] != '(') {
            printf("%s %d\n", "SyntaxError: Unexpected ')' on line", line_num);
            return 1;
          } else 
            --token_index;
          break;

        case ';':
          if (token_index > -1 && 
              (tokens[token_index] == '[' || tokens[token_index] == '(')
             ) {
            printf("%s %d:\n", "SyntaxError: Unexpected ';' on line", line_num);
            printf("%s", current);
            return 1;
          }
      }
    }

    // AFTER WE FINISH WALKING DOWN LINE
    if (in_single_quotes) {
      printf("%s %d:\n", 
          "SyntaxError: Missing closing single quote on line" , line_num);
      printf("%s", current);
      in_single_quotes = 0;
    }

    if (in_double_quotes) {
      printf("%s %d:\n", 
          "SyntaxError: Missing closing double quote on line" , line_num);
      printf("%s", current);
      in_double_quotes = 0;
    }
  }

  // AFTER WE FINISH WITH ALL LINES
  if (in_block_comment) {
    printf("%s\n", "SyntaxError: Did not close block comment.");
    return 1;
  }

  if (token_index != -1) {
    printf("%s %c\n", "SyntaxError: Missing closer for", tokens[token_index]);
    return 1;
  }


  return 0;
}

int mygetline(char line[], int maxwidth) {
  char c, i;

  for (i = 0; i < maxwidth - 1 && (c = getchar()) != EOF && c != '\n'; ++i)
    line[i] = c;

  if (c == '\n') {
    line[i] = c;
    ++i;
  }

  line[i] = '\0';

  return i;
}
