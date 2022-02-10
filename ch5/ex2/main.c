#include <stdio.h>
#include <ctype.h>

int getch(void);
void ungetch(int);

int getfloat(double *pn) {
  double power;
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

  for (*pn = 0.0; isdigit(c); c = getch())
    *pn = 10.0 * *pn + (c - '0');

  if (c == '.')
    c = getch();

  for (power = 1.0; isdigit(c); c = getch()) {
    *pn = 10.0 * *pn + (c - '0');
    power *= 10.0;
  }

  *pn = sign * *pn / power;

  if (c != EOF)
    ungetch(c);

  return c;
}

int main() {
  double f;
  int result;

  while ((result = getfloat(&f)) != EOF)
    if (result > 0)
      printf("%f\n", f);

  return 0;
}
