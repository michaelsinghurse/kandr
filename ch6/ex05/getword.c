#include <stdio.h>
#include <ctype.h>

int getword(char *word, int lim)
{
  int c, getch(void);
  void ungetch(int);
  char *w = word;

  while (isspace(c = getch()) && c != '\n')
    ;

  // comment - read to NL if single-line comment or closing tag if multi-line
  if (c == '/')
    if ((c = getch()) == '/') {
      while (getch() != '\n')
        ;

      return getword(word, lim);
    } else if (c == '*') {
      while (1)
        if ((c = getch()) == '*')
          if ((c = getch()) == '/')
            break;

      return getword(word, lim);
    } else
      ungetch(c);

  // string constants - ignore everything within double quotes
  if (c == '"') {
    while ((c = getch()) != '"')
      ;

    return getword(word, lim);
  }

  if (c != EOF)
    *w++ = c;

  if (!isalpha(c) && c != '_') {
    *w = '\0';
    return c;
  }

  for ( ; --lim > 0; w++)
    if (!isalnum(*w = getch()) && *w != '_') {
      ungetch(*w);
      break;
    }

  *w = '\0';
  return *word;
}

