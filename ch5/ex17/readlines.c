#include <stdio.h>

#define MAXWIDTH 1000

int mygetline(char *, int);

int readlines(char *lineptr[], int maxlines)
{
  int len, nlines;
  char line[MAXWIDTH * maxlines];
  char *pline;

  nlines = 0;
  pline = line;
  while ((len = mygetline(pline, MAXWIDTH)) > 0) {
    if (nlines >= maxlines)
      return -1;

    lineptr[nlines++] = pline;
    pline += (len + 1);
  }

  return nlines;
}

int mygetline(char *line, int maxwidth)
{
  char c;
  char *pline;

  pline = line;
  while (line - pline < maxwidth - 1 && (c = getchar()) != EOF && c != '\n')
    *line++ = c;

  if (c == '\n')
    *line++ = c;

  *line = '\0';

  return line - pline;
}
