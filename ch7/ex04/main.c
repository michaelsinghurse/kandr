#include <ctype.h>
#include <stdio.h>
#include <stdarg.h>
#include <string.h>
#include <stdlib.h>

void minscanf(char *, ...);

int main(int argc, char **argv)
{
  int day, month, year;
  char monthname[20];

  minscanf("%d %s %d", &day, monthname, &year);
  printf("%s, %d %d\n", monthname, day, year);

  minscanf("%d/%d/%d", &month, &day, &year);
  printf("%d-%d-%d\n", month, day, year);
  
  return 0;
}

void minscanf(char *fmt, ...)
{
  va_list ap;
  char c, *pfmt, s[20], *ps, *psval;
  int *pival, getch(void);
  double *pdval;
  void ungetch(int);

  va_start(ap, fmt);

  ps = s;
  for (pfmt = fmt; *pfmt; pfmt++) {
    if (isspace(*pfmt))
      continue;
    else if (*pfmt != '%') {
      do {
        c = getch();
      } while (isspace(c));

      if (*pfmt != c)
        return;
    } else {
      do {
        c = getch();
      } while (isspace(c));

      switch(*++pfmt) {
        case 'd':
          for (*ps = c; isdigit(*ps); *++ps = getch())
            ;
          ungetch(*ps);
          *ps = '\0';

          pival = va_arg(ap, int *);
          *pival = atoi(s);
          break;
        case 'f':
          for (*ps = c; isdigit(*ps) || *ps == '.'; *++ps = getch())
            ;
          ungetch(*ps);
          *ps = '\0';

          pdval = va_arg(ap, double *);
          *pdval = atof(s);
          break;
        case 's':
          for (*ps = c; !isspace(*ps); *++ps = getch())
            ;
          *ps = '\0';

          psval = va_arg(ap, char *);
          strcpy(psval, s); 
          break;
        default:
          printf("Invalid conversion spec: %%%c\n", *pfmt);
      }

      ps = s;
    }
  }

  va_end(ap);
}

