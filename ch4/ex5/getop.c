#include <stdio.h>
#include <ctype.h>

#define NUMBER '0'

int getch(void);
void ungetch(int);

int getop(char s[]) {
  int c, i;

  while ((s[0] = c = getch()) == ' ' || c == '\t')
    ;

  s[1] = '\0';

  if (!isdigit(c) && c != '.' && c != '-')
    return c;

  i = 0;

  if (c == '-') {
    c = getch();

    if (isdigit(c))
      s[++i] = c;
    else {
      ungetch(c);
      return '-';
    }
  }

  if (isdigit(c))
    while (isdigit(s[++i] = c = getch()))
      ;

  if (c == '.')
    while (isdigit(s[++i] = c = getch()))
      ;
  
  s[i] = '\0';

  if (c != EOF)
    ungetch(c);

  return NUMBER;
}
