#include <stdio.h>

int mygetline(char *s, int lim)
{
  char c;
  char *ps;

  ps = s;

  while (--lim > 0 && (c = getchar()) != EOF && c != '\n')
    *s++ = c;

  if (c == '\n')
    *s++ = c;

  *s = '\0';

  return s - ps;
}
