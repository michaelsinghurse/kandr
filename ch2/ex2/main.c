#include <stdio.h>

#define MAXLINE 1000

int mygetline(char s[], int m);

int main() {
  char line[MAXLINE];

  while (mygetline(line, MAXLINE) > 0)
    printf("%s", line);

  return 0;
}

int mygetline(char line[], int lim) {
  int c, i;
  
  i = 0;
  while (i < lim - 1) {
    c = getchar();

    if (c == '\n')
      break;

    if (c == EOF)
      break;

    line[i] = c;

    ++i;
  }

  if (c == '\n') {
    line[i] = c;
    ++i;
  }

  line[i] = '\0';

  return i;
}
