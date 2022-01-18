#include <stdio.h>

#define FOLDWIDTH 80
#define MAXLINE 1000

int mygetline(char s[], int m);
int fold(char s[], char t[], int m);
void copy(char s[], char t[]);
int iswhitespace(char c);

int main() {
  int len;
  char current[MAXLINE];
  char extra[MAXLINE - FOLDWIDTH];

  while (mygetline(current, MAXLINE) > 0)
    do {
      len = fold(current, extra, FOLDWIDTH);

      printf("%s", current);

      copy(extra, current);
    } while (len > 0);

  return 0;
}


int mygetline(char line[], int maxwidth) {
  int c, i;

  for (i = 0; i < maxwidth && (c = getchar()) != EOF && c != '\n'; ++i)
    line[i] = c;

  if (c == '\n') {
    line[i] = c;
    ++i;
  }

  line[i] = '\0';

  return i;
}

int fold(char line[], char extra[], int foldwidth) {
  int i, j;
  int len_line = 0;

  while (line[len_line] != '\0')
    ++len_line;

  if (len_line <= foldwidth) {
    extra[0] = '\0';
    return 0;
  }

  // i is the index of the last space before the fold
  for (i = foldwidth - 1; !iswhitespace(line[i]) && i >= 0; --i) ;

  if (i < 0) {
    extra[0] = '\0';
    return 0;
  }

  if (line[i] != '\n')
    line[i] = '\n';

  int line_null_idx = i + 1;

  // i is the first non-space after the fold
  for (i = i + 1; iswhitespace(line[i]) && line[i] != '\0'; ++i) ;

  for (j = 0; line[i] != '\0'; ++j) {
    extra[j] = line[i];
    ++i;
  }

  line[line_null_idx] = '\0';
  extra[j] = '\0';

  return j;
}

void copy(char from[], char to[]) {
  int i;

  for (i = 0; from[i] != '\0'; ++i)
    to[i] = from[i];

  to[i] = '\0';
}

int iswhitespace(char c) {
  return c == ' ' || c == '\t' || c == '\n';
}
