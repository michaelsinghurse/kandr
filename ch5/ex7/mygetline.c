#include <stdio.h>

int mygetline(char *s, int lim) {
  int c, i;

  i = 0;
  while (i < lim-1 && (c = getchar()) != EOF && c != '\n')
    s[i++] = c;

  if (c == '\n')
    s[i++] = c;

  s[i] = '\0';

  return i;
}
    
