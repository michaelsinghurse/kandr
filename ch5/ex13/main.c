#include <stdio.h>
#include <stdlib.h>

#define MAXWIDTH 1000
#define MAXLINES 5000
#define N_LINES 10

int mygetline(char *, int);
void writelastnlines(char *[], int, int);

int main(int argc, char *argv[])
{
  char line[MAXWIDTH * MAXLINES];
  char *pline;
  char *lines[MAXLINES];
  int len, linesc, nlines;

  nlines = N_LINES;
  if (argc > 1 && *argv[1] == '-')
    nlines = atoi(++argv[1]);

  linesc = 0;
  pline = line;
  while (linesc < MAXLINES && (len = mygetline(pline, MAXWIDTH)) > 0) {
    lines[linesc++] = pline;
    pline += (len + 1);
  }

  writelastnlines(lines, linesc, nlines);

  return 0;
}

void writelastnlines(char *lines[], int linesc, int nlines)
{
  if (nlines > linesc)
    nlines = linesc;

  while (nlines > 0) {
    printf("%s", lines[linesc-nlines]);
    nlines--;
  }
}
