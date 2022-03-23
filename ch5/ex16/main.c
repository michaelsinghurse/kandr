#include <stdio.h>
#include <string.h>

#define MAXLINES 5000
char *lineptr[MAXLINES];

int readlines(char *lineptr[], int nlines);
void writelines(char *lineptr[], int nlines, int reverse);

void qsort(void *lineptr[], int left, int right,
           int (*comp)(void *, void *));
int numcmp(const char *, const char *);
int strcmpci(const char *, const char *);
int strcmpdo(const char *, const char *);
int strcmpdoci(const char *, const char *);

int main(int argc, char *argv[])
{
  char c;
  int nlines, numeric = 0, reverse = 0, foldcase = 0, dirorder = 0;
  int (*comp)(const char *, const char *);

  while (--argc > 0 && (*++argv)[0] == '-')
    while (c = *++argv[0])
      switch (c) {
        case 'n':
          numeric = 1;
          break;
        case 'r':
          reverse = 1;
          break;
        case 'f':
          foldcase = 1;
          break;
        case 'd':
          dirorder = 1;
          break;
        default:
          printf("invalid option: %c\n", c);
          return 1;
      }

  if (numeric)
    comp = numcmp;
  else if (foldcase && !dirorder)
    comp = strcmpci;
  else if (foldcase && dirorder)
    comp = strcmpdoci;
  else if (dirorder)
    comp = strcmpdo;
  else
    comp = strcmp;

  if ((nlines = readlines(lineptr, MAXLINES)) >= 0) {
    qsort((void **) lineptr, 0, nlines-1, (int (*)(void *, void *)) comp);
    writelines(lineptr, nlines, reverse);
    return 0;
  } else {
    printf("input too big to sort\n");
    return 1;
  }
}
