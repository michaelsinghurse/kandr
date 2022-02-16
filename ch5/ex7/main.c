#include <stdio.h>
#include <string.h>

#define MAXLEN 1000
#define MAXLINES 5000

char *lineptr[MAXLINES];

int readlines_v1(char *v[], int);
int readlines_v2(char *v[], char *, int);
void qsort(char *v[], int, int);
void writelines(char *v[], int);

int main() {
  int nlines;
  char lines[MAXLINES * MAXLEN];

  if ((nlines = readlines_v2(lineptr, lines, MAXLINES * MAXLEN)) >= 0) {
    qsort(lineptr, 0, nlines-1);
    writelines(lineptr, nlines);
    return 0;
  } else {
    printf("error: input too big to sort\n");
    printf("\tlines read: %d\n", nlines);
    return 1;
  }
}

int mygetline(char *, int);
char *alloc(int);

int readlines_v1(char *lineptr[], int maxlines) {
  int len, nlines;
  char *p, line[MAXLEN];

  nlines = 0;

  while ((len = mygetline(line, MAXLEN)) > 0)
    if (nlines >= maxlines || (p = alloc(len)) == NULL)
      return -1;
    else {
      line[len-1] = '\0';
      strcpy(p, line);
      lineptr[nlines++] = p;
    }

  return nlines;
}

int readlines_v2(char *lineptr[], char *lines, int maxchars) {
  int len, nlines;
  char *p;

  nlines = 0;
  p = lines;

  while ((len = mygetline(p, lines + maxchars - p)) > 0)
    if (p + len > lines + maxchars)
      return -1;
    else {
      *(p + len - 1) = '\0';
      lineptr[nlines++] = p;
      p += len;
    }

  return nlines;
}

void writelines(char *lineptr[], int nlines) {
  while (nlines-- > 0)
    printf("%s\n", *lineptr++);
}

