#include <ctype.h>

static int isdochar(char c)
{
  return isalnum(c) || isspace(c);
}

int strcmpdo(const char *s, const char *t)
{
  while (*s != '\0' && *t != '\0')
    if (!isdochar(*s))
      s++;
    else if (!isdochar(*t))
      t++;
    else {
      if (*s != *t)
        return *s - *t;

      s++;
      t++;
    }

  return *s - *t;
}

int strcmpdoci(const char *s, const char *t)
{
  while (*s != '\0' && *t != '\0')
    if (!isdochar(*s))
      s++;
    else if (!isdochar(*t))
      t++;
    else {
      if (tolower(*s) != tolower(*t))
        return tolower(*s) - tolower(*t);

      s++;
      t++;
    }

  return tolower(*s) - tolower(*t);
}
