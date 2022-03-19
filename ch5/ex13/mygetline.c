#include <stdio.h>

int mygetline(char *line, int maxwidth)
{
  char c, *pline;

  pline = line;
  while (line-pline < maxwidth-1 && (c = getchar()) != EOF && c != '\n')
    *line++ = c;

  if (c == '\n')
    *line++ = c;

  *line == '\0';

  return line - pline; 
}
