#include <stdio.h>
#include <ctype.h>

#define NUMBER '0'

int getop(char *s) {
  if ((*s = getchar()) == '\n')
    return *s;
  else
    ungetc(*s, stdin);

  scanf("%s", s);

  if (!isdigit(*s) && *s != '.' && *s != '-')
    return *s;

  if (*s == '-' && s[1] == '\0')
    return '-';

  return NUMBER;
}

