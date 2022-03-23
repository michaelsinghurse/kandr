#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXLINES 5000
char *lineptr[MAXLINES];

int readlines(char *lineptr[], int nlines);
void writelines(char *lineptr[], int nlines, int reverse);

void myqsort(void *lineptr[], int left, int right,
           int (*comp)(void *, void *), int field, char delim);
int numcmp(const char *, const char *);
int strcmpci(const char *, const char *);
int strcmpdo(const char *, const char *);
int strcmpdoci(const char *, const char *);

/*
 * Usage: a.out [--delim=c] [--field=i] [-dfnr]
 *
 * --delim=c: used for field-handling. field delimiter is c, e.g. comma or vertical bar
 * --field=i: sort on the ith field, 1 based.
 * -d: sort in directory order (compare only letters, numbers, and blanks)
 * -f: fold upper and lower case together (case insensitive)
 * -n: numeric sort
 * -r: reverse sort order
 */
int main(int argc, char *argv[])
{
  char c;
  int nlines, numeric = 0, reverse = 0, foldcase = 0, dirorder = 0;
  int (*comp)(const char *, const char *);
  char field_delim = '\0';
  int field_num = 0;

  while (--argc > 0 && (*++argv)[0] == '-')
    if (strncmp(*argv, "--delim=", 8) == 0)
      field_delim = (*argv)[8];
    else if (strncmp(*argv, "--field=", 8) == 0)
      field_num = atoi(&(*argv)[8]);
    else
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
    myqsort((void **) lineptr, 0, nlines-1, (int (*)(void *, void *)) comp,
            field_num, field_delim);
    writelines(lineptr, nlines, reverse);
    return 0;
  } else {
    printf("input too big to sort\n");
    return 1;
  }
}
