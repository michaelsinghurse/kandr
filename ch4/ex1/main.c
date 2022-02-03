#include <stdio.h>

#define MAXLINE 1000

int mygetline(char s[], int m);
int strindex(char s[], char t[]);

int main() {
  char pattern[] = "int";
  char line[MAXLINE];
  int found;

  found = 0;
  while ((mygetline(line, MAXLINE)) > 0)
    if (strindex(line, pattern) > -1) {
      printf("%s", line);
      ++found;
    }

  return found;
}

int mygetline(char line[], int max) {
  int c, i;

  i = 0;
  while (i < max - 1 && (c = getchar()) != EOF && c != '\n')
    line[i++] = c;

  if (c == '\n')
    line[i++] = c;

  line[i] = '\0';

  return i;
}

/* return index of rightmost occurence of needle in haystack,
 * or -1 if there is none
 */
int strindex(char haystack[], char needle[]) {
  int i, j, k;

  for (i = 0; haystack[i] != '\0'; ++i)
    ;

  for (i -= 1; i >= 0; --i) {
    for (j = i, k = 0; needle[k] != '\0' && haystack[j] == needle[k]; ++j, ++k)
      ;

    if (k > 0 && needle[k] == '\0')
      return i;
  }

  return -1;
}

