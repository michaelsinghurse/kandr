#include <stdio.h>
#include <ctype.h>

int getch(void);
void ungetch(int);

int getint(int *pn) {
  int c, sign, temp;

  while (isspace(c = getch()))
    ;

  if (!isdigit(c) && c != EOF && c!= '+' && c != '-') {
    ungetch(c);
    return 0;
  }

  sign = (c == '-') ? -1 : 1;

  if (c == '+' || c == '-') {
    temp = c;
    c = getch();

    if (!isdigit(c)) {
      ungetch(c);
      ungetch(temp);
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

int main() {
  int n, result;

  while ((result = getint(&n)) != EOF)
    if (result > 0)
      printf("%d\n", n);

  return 0;
}
