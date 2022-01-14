#include <stdio.h>

#define MAXWIDTH 1000

int mygetline(char s[], int m);
void reverse(char s[]);

int main() {
  int len;
  char current[MAXWIDTH];

  while ((len = mygetline(current, MAXWIDTH)) > 0) {
    reverse(current);
    printf("%s", current);
  }

  return 0;
}

int mygetline(char s[], int maxwidth) {
  int c, i;

  for (i = 0; i < maxwidth - 1 && (c = getchar()) != EOF && c != '\n'; ++i)
    s[i] = c;

  if (c == '\n') {
    s[i] = '\n';
    ++i;
  }

  s[i] = '\0';

  return i;
}

void reverse(char s[]) {
  int len;

  for (len = 0; s[len] != '\0'; ++len) ;

  for (int i = 0; i < len / 2; ++i) {
    int j = len - 1 - i;
    int c = s[i];
    s[i] = s[j];
    s[j] = c;
  }
}

