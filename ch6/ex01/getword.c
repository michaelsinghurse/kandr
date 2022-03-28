#include <stdio.h>
#include <ctype.h>

/*
 * TODO:
 * - underscores - my_var, _var
 * - string constants `"int"` - should not count toward int keyword
 * X comments - ignore everything in comments
 * X preprocessor control lines - lines beginning with `#` perhaps proceeded by
 *   whitespace
 */
int getword(char *word, int lim)
{
  int c, getch(void);
  void ungetch(int);
  char *w = word;

  while (isspace(c = getch()))
    ;

  // preprocessor control line - read to first non-whitespace char on next line
  if (c == '#') {
    while (getch() != '\n')
      ;

    while (isspace(c = getch()))
      ;
  }

  // comment - read to end of line if single-line comment and to closing
  // token if multi-line comment
  if (c == '/')
    if ((c = getch()) == '/') {
      while (getch() != '\n')
        ;

      while (isspace(c = getch()))
        ;
    } else if (c == '*') {
      while (1)
        if ((c = getch()) == '*')
          if ((c = getch()) == '/')
            break;

      while (isspace(c = getch()))
        ;
    } else
      ungetch(c);

  if (c != EOF)
    *w++ = c;

  if (!isalpha(c)) {
    *w = '\0';
    return c;
  }

  for ( ; --lim > 0; w++)
    if (!isalnum(*w = getch())) {
      ungetch(*w);
      break;
    }

  *w = '\0';
  return *word;
}
