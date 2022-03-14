#include <stdio.h>

int mygetline(char *line, int max)
{
  char c;
  int n;

  n = 0;
  while (n < max-1 && (c = getchar()) != EOF && c != '\n')
    line[n++] = c;

  if (c == '\n')
    line[n++] = c;

  line[n] = '\0';

  return n;
}
