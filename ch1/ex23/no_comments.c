#include <stdio.h>

#define MAXLINE 1000

int mygetline(char s[], int m);

int main() {
  int i, c;
  char current[MAXLINE];
  int in_double_quotes = 0;
  int in_single_quotes = 0;
  int was_slash = 0;
  int in_block_comment = 0;
  int was_asterisk = 0;

  while (mygetline(current, MAXLINE) > 0) {
    for (i = 0; (c = current[i]) && c != '\0'; ++i) {
      if (c == '\"' && in_double_quotes)
        in_double_quotes = 0;
      else if (c == '\"' && !in_double_quotes)
        in_double_quotes = 1;

      if (c == '\'' && in_single_quotes)
        in_single_quotes = 0;
      else if (c == '\'' && !in_single_quotes)
        in_single_quotes = 1;
    
      if (c == '*' && was_slash && !in_double_quotes && !in_single_quotes) {
        in_block_comment = 1;
        was_slash = 0;
        current[i - 1] = '\n';
        current[i] = '\0';
      } else if (c == '*' && in_block_comment && !in_double_quotes && !in_single_quotes)
        was_asterisk = 1;
      else if (c == '/' && in_block_comment && was_asterisk && !in_double_quotes && !in_single_quotes) {

      if (c != '*')
        was_asterisk = 0;

 
      if (c == '/' && !was_slash)
        was_slash = 1;
      else if (c == '/' && was_slash && !in_double_quotes && !in_single_quotes) {
        current[i - 1] = '\n';
        current[i] = '\0';
      } else
        was_slash = 0;
    }

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
