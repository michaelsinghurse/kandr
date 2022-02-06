#include <stdio.h>

#define BUFSIZE 100

int bp = 0;
char buf[BUFSIZE];

int getch(void) {
  return bp > 0 ? buf[--bp] : getchar();
}

void ungetch(int c) {
  if (bp < BUFSIZE)
    buf[bp++] = c;
  else
    printf("ungetch: too many characters\n");
}
