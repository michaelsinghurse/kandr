#include <stdio.h>

#define MINPRINT 80
#define MAXWIDTH 1000

int mygetline(char s[], int maxwidth);

int main() {
  int len;
  char current[MAXWIDTH];
  
  while ((len = mygetline(current, MAXWIDTH)) != 0)
    if (len > MINPRINT) {
      printf("%s", current);
      if (current[len - 1] != '\n')
        printf("\n");
    }
    
  return 0;
}

int mygetline(char s[], int maxwidth) {
  int c, i;

  for (i = 0; i < maxwidth - 1 && (c = getchar()) != EOF && c != '\n'; ++i)
    s[i] = c;

  if (c == '\n') {
    s[i] = c;
    ++i;
  }

  s[i] = '\0';

  return i;
}
