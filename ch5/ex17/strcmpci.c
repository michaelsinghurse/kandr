#include <ctype.h>

int strcmpci(const char *s, const char *t)
{
  for ( ; tolower(*s) == tolower(*t); s++, t++)
    if (*s == '\0') // could have also said *t == '\0'
      return 0;

  return tolower(*s) - tolower(*t);
}
