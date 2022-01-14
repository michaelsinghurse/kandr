#include <stdio.h>

#define TABWIDTH 4
#define MAXLINE 1000

int mygetline(char s[], int m);
void replacetabs(char s[], int m);

/*
 * Replace tabs in input with proper number of spaces
 * to arrive at next tab stop.
 */
int main() {
  int len;
  char line[MAXLINE];

  while ((len = mygetline(line, MAXLINE)) > 0) {
    replacetabs(line, TABWIDTH);
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

/*
 * copy the input string into a temporary array
 * maintain two pointers, i and j
 * use j to walk down the copy. for each j...
 * - if copy[j] IS NOT a tab
 *   - replace original[i] with copy[j]
 * - if copy[j] IS a tab
 *   - figure out how many spaces until next tab stop
 *   - replace original[i] to original[i+num] with spaces
 * - increment i and j by 1
 * add a null mark at original[i]
 */
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
  while (1) {
    if (copy[j] == '\t') {
      int spaces = tabwidth - (i % tabwidth);

      while (spaces > 0) {
        original[i] = ' ';
        ++i;
        --spaces;
      }
    } else
      original[i] = copy[j];

    if (copy[j] == '\0')
      break;
    
    ++i;
    ++j;
  }
}
