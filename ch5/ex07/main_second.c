#include <stdio.h>
#include <string.h>

#define MAXLINES 5000
#define MAXLEN 1000

int readlines(char *v[], char *, int);
void writelines(char *v[], int);
void qsort(char *v[], int, int);

int main(int argc, char *argv[])
{
  int nlines;
  char *lineptr[MAXLINES];
  char lines[MAXLINES * MAXLEN];

  nlines = readlines(lineptr, lines, MAXLINES);

  if (nlines < 0) {
    printf("error: input too big to sort\n");
    return -1;
  }

  qsort(lineptr, 0, nlines-1);
  writelines(lineptr, nlines);
  
  return 0;
}

int readlines(char *lineptr[], char *lines, int maxlines)
{
  int len, nlines;
  int mygetline(char *, int);

  nlines = 0;
  while ((len = mygetline(lines, MAXLEN)) > 0)
    if (nlines >= maxlines)
      return -1;
    else {
      lines[len-1] = '\0';
      lineptr[nlines++] = lines;
      lines += len;
    }

  return nlines;
}

void writelines(char *lineptr[], int nlines)
{
  while (nlines-- > 0)
    printf("%s\n", *lineptr++);
}

void qsort(char *v[], int left, int right)
{
  int i, last;
  void swap(char *v[], int i, int j);

  if (left >= right)
    return;
  swap(v, left, (left + right)/2);
  last = left;
  for (i = left+1; i <= right; i++)
    if(strcmp(v[i], v[left]) < 0)
      swap(v, ++last, i);
  swap(v, left, last);
  qsort(v, left, last-1);
  qsort(v, last+1, right);
}

void swap(char *v[], int i, int j)
{
  char *temp;

  temp = v[i];
  v[i] = v[j];
  v[j] = temp;
}
  
