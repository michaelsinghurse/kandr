#include <stdio.h>

#define MAXLINE 1000

int mygetline(char s[], int m);

int main() {
  int i, c;
  int prev_c = -1;
  char current[MAXLINE];
  int in_double_quotes = 0;
  int in_single_quotes = 0;
  int in_block_comment = 0;
  int block_comment_start = 0;
  int break_loop = 0;

  while (mygetline(current, MAXLINE) > 0) {
    for (i = 0; (c = current[i]) && c != '\0'; ++i) {
      switch (c) {
        case '\"':
          if (in_double_quotes)
            in_double_quotes = 0;
          else if (!in_single_quotes)
            in_double_quotes = 1;
          break;

        case '\'':
          if (in_single_quotes)
            in_single_quotes = 0;
          else if (!in_double_quotes)
            in_single_quotes = 1;
          break;

        case '/':
          if (prev_c == '/' && !in_double_quotes && !in_single_quotes && !in_block_comment) {
            current[i - 1] = '\n';
            current[i] = '\0';
            break_loop = 1;
          }
          else if (prev_c == '*' && in_block_comment) {
            current[block_comment_start] = '\n';
            current[block_comment_start + 1] = '\0';
            in_block_comment = 0;
            break_loop = 1;
          }
          break;

        case '*':
          if (prev_c == '/' && !in_double_quotes && !in_single_quotes) {
            in_block_comment = 1;
            block_comment_start = i - 1;
          }
          break;
      }

      if (break_loop) {
        break_loop = 0;
        break;
      }

      prev_c = c;
    }

    if (in_block_comment) {
      current[block_comment_start] = '\n';
      current[block_comment_start + 1] = '\0';
      block_comment_start = 0;
    }

    in_double_quotes = 0;
    in_single_quotes = 0;
    prev_c = -1;

    printf("%s", current);
  }

  return 0;
}

int mygetline(char line[], int maxwidth) {
  int c, i;

  for (i = 0; 
       i < maxwidth - 1 && (c = getchar()) != EOF && c != '\n';
       ++i)
    line[i] = c;

  if (c == '\n') {
    line[i] = c;
    ++i;
  }

  line[i] = '\0';

  return i;
}
