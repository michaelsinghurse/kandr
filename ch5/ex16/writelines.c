#include <stdio.h>

void writelines(char *lineptr[], int nlines, int reverse)
{
  while (nlines--)
    printf("%s", reverse ? lineptr[nlines] : *lineptr++);
}
