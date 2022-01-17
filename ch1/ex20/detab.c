#include <stdio.h>

#define TABWIDTH 4
#define MAXLINE 1000

int mygetline(char s[], int m);
void replacetabs(char s[], int m, int n);

/*
 * Replace tabs in input with proper number of spaces
 * to arrive at next tab stop.
 */
int main() {
  int len;
  char line[MAXLINE];

  while ((len = mygetline(line, MAXLINE)) > 0) {
    replacetabs(line, TABWIDTH, MAXLINE);
    printf("%s", line);
  }

  return 0;
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

void replacetabs(char original[], int tabwidth, int maxline) {
  int i, j;
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
      int spaces = tabwidth - (i % tabwidth);

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
