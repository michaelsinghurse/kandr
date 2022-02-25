#include <stdio.h>
#include <ctype.h>

int getch(void);
void ungetch(int);
int getfloat(double *);

int main(int argc, char *argv) {
  int c;
  double f;

  while ((c = getfloat(&f)) != EOF) {
    if (c > 0)
      printf("Number: %f\n", f);

    // read to end of line
    while (c = getch())
      if (c == EOF)
        return 0;
      else if (c == '\n')
        break;
  }

  return 0;
}

int getfloat(double *pn) {
  int c, prev, sign;
  double power;

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

  for (*pn = 0.0; isdigit(c); c = getch())
    *pn = 10.0 * *pn + (c - '0');

  if (c == '.')
    c = getch();

  for (power = 1.0; isdigit(c); power *= 10.0, c = getch())
    *pn = 10.0 * *pn + (c - '0');

  *pn = sign * *pn / power;

  if (c != EOF)
    ungetch(c);

  return c;
}

