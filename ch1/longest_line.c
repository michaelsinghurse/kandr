#include <stdio.h>
#define MAXWIDTH 1000

int mygetline(char line[], int maxline);
void copy(char from[], char to[]);

int main() {
  int width;
  int max = 0;
  char current[MAXWIDTH];
  char longest[MAXWIDTH];

  while ((width = mygetline(current, MAXWIDTH)) != 0)
    if (width > max) {
      max = width;
      copy(current, longest);
    }

  printf("Length: %d\n", max);
  printf("Line: %s", longest);

  return 0;
}

int mygetline(char line[], int maxwidth) {
  int c, i;

  for (i = 0; i < maxwidth && (c = getchar()) != EOF && c != '\n'; ++i)
    line[i] = c;

  if (c == '\n') {
    line[i] = c;
    ++i;
  }

  line[i] = '\0';

  return i;
}

void copy(char from[], char to[]) {
  int i = 0; 

  while ((to[i] = from[i]) != '\0')
    ++i;
}

