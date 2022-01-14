#include <stdio.h>

#define MAXWIDTH 1000

int mygetline(char s[], int maxwidth);
void removews(char s[]);

int main() {
  int len;
  char current[MAXWIDTH];

  while ((len = mygetline(current, MAXWIDTH)) > 0)
    if (len > 1) {
      removews(current);
      printf("%s", current);
    }

  return 0;
}

int mygetline(char s[], int maxwidth) {
  int c, i;

  for (i = 0; i < maxwidth -1 && (c = getchar()) != EOF && c != '\n'; ++i)
    s[i] = c;

  if (c == '\n') {
    s[i] = c;
    ++i;
  }

  s[i] = '\0';

  return i;
}

// assume only whitespace chars to remove are spaces and tabs
void removews(char s[]) {
  int c, i;
  int lastwordidx = -1;

  for (i = 0; (c = s[i]) != '\0' && c != '\n'; ++i)
    if (c != ' ' && c != '\t')
      lastwordidx = i;

  if (c == '\n') {
    s[lastwordidx + 1] = c;
    s[lastwordidx + 2] = '\0';
  } else
    s[lastwordidx + 1] = '\0';
}
