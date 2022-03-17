#include <stdio.h>
#include <stdlib.h>

#define MAXLINE 1000

int mygetline(char s[], int m);
void replacetabs(char s[], int t[], int m, int n);

/*
 * Replace tabs in input with proper number of spaces
 * to arrive at next tab stop.
 *
 * Tabstops are provided via CL arguments.
 */
int main(int argc, char *argv[]) {
  int i, len;
  char line[MAXLINE];
  int tabstops[MAXLINE];

  i = 1;
  while (i < argc) {
    if ((tabstops[i-1] = atoi(argv[i])) == 0) {
      printf("error: invalid tabstop: %s\n", argv[i]);
      return 1;
    }
    i++;
  }
 
  while ((len = mygetline(line, MAXLINE)) > 0) {
    replacetabs(line, tabstops, i-1, MAXLINE);
    printf("%s", line);
  }

  return 0;
}

void replacetabs(char original[], int tabstops[], int numtabs, int maxline) {
  int i, j;
  char copy[maxline];
  int tabwidth = 8;

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
      int spaces;

      if (numtabs > 0) {
        while (numtabs > 0 && *tabstops <= i) {
          numtabs--;
          tabstops++;
        }

        if (numtabs > 0)
          spaces = *tabstops - i;
        else
          spaces = tabwidth - (i % tabwidth);
      } else
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
