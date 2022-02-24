#include <stdio.h>
#include <ctype.h>

int getch(void);
void ungetch(int);
int getint(int *);

int main(int argc, char *argv) {
  int c, n;

  while ((c = getint(&n)) != EOF) {
    if (c > 0)
      printf("Number: %d\n", n);

    // read to end of line
    while (c = getch())
      if (c == EOF)
        return 0;
      else if (c == '\n')
        break;
  }

  return 0;
}

int getint(int *pn) {
  int c, prev, sign;

  while (isspace(c = getch()))
    ;

  if (!isdigit(c) && c != EOF && c != '+' && c != '-') {
    ungetch(c);
    return 0;
  }

  sign = (c == '-') ? -1 : 1;

  if (c == '+' || c == '-') {
    prev = c;
    c = getch();

    if (!isdigit(c)) {
      ungetch(c);
      ungetch(prev);
      return 0;
    }
  }

  for (*pn = 0; isdigit(c); c = getch())
    *pn = 10 * *pn + (c - '0');

  *pn *= sign;

  if (c != EOF)
    ungetch(c);

  return c;
}

