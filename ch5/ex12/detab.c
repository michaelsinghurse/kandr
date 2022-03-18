#include <stdio.h>
#include <stdlib.h>

#define TABWIDTH 4
#define MAXLINE 1000

int mygetline(char s[], int m);
void replacetabs(char *, int, int, int);

/*
 * Replace tabs in input with proper number of spaces
 * to arrive at next tab stop.
 *
 * detab -m +n
 * tab stops every n columns starting at column m
 */
int main(int argc, char *argv[])
{
  int len;
  char line[MAXLINE];
  int firstcol = TABWIDTH;
  int tabwidth = TABWIDTH;

  while (--argc > 0 && argv++)
    if ((*argv)[0] == '-')
      firstcol = atoi(++argv[0]);
    else if ((*argv)[0] == '+')
      tabwidth = atoi(++argv[0]);
    else {
      printf("invalid argument: %s\n", *argv);
      printf("usage: entab -m +n\n");
      return 1;
    }

  while ((len = mygetline(line, MAXLINE)) > 0) {
    replacetabs(line, firstcol, tabwidth, MAXLINE);
    printf("%s", line);
  }

  return 0;
}

void replacetabs(char original[], int firstcol, int tabwidth, int maxline)
{
  int i, j, spaces;
  char copy[maxline];

  i = 0;
  while (1) {
    copy[i] = original[i];
    if (original[i] == '\0')
      break;
    ++i;
  }

  i = 0;
  j = 0;
  while (i < maxline - 1) {
    if (copy[j] == '\t') {
      if (i < firstcol)
        spaces = firstcol - i;
      else
        spaces = tabwidth - (i % tabwidth);

      while (spaces > 0) {
        original[i] = ' ';
        ++i;
        --spaces;
      }

      --i;
    } else
      original[i] = copy[j];

    if (copy[j] == '\0')
      break;
    
    ++i;
    ++j;
  }

  if (i == maxline - 1)
    original[i] = '\0';
}

int mygetline(char s[], int max) {
  int c, i;

  for (i = 0; i < max - 1 && (c = getchar()) != EOF && c != '\n'; ++i)
    s[i] = c;

  if (c == '\n') {
    s[i] = c;
    ++i;
  }

  s[i] = '\0';

  return i;
}

