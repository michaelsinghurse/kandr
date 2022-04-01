#include <stdio.h>
#include <stdarg.h>

void minprintf(char *, ...);

int main(int argc, char **argv)
{
  int d;
  double f;
  char *s;

  d = 5;
  f = 5.0;
  s = "five";
  minprintf("int %d, double %f, string %s\n", d, f, s); 

  return 0;
}

void minprintf(char *fmt, ...)
{
  va_list ap;
  char *p, *sval;
  int ival;
  double dval;

  va_start(ap, fmt);

  for (p = fmt; *p; p++) {
    if (*p != '%') {
      putchar(*p);
      continue;
    }

    switch (*++p) {
      case 'd':
        ival = va_arg(ap, int);
        printf("%d", ival);
        break;
      case 'f':
        dval = va_arg(ap, double);
        printf("%f", dval);
        break;
      case 's':
        for (sval = va_arg(ap, char *); *sval; sval++)
          putchar(*sval);
        break;
      default:
        putchar(*p);
        break;
    }
  }

  va_end(ap);
}

