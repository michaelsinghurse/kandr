#include <ctype.h>

static int isdochar(char c)
{
  return isalnum(c) || isspace(c);
}

int strcmpdo(const char *s, const char *t)
{
  while (*s != '\0') {
    if (isdochar(*s) && isdochar(*t) && *s != *t)
        return *s - *t;
 
    s++;
    t++;
  }

  return *t == '\0' ? 0 : (*s - *t);
}

int strcmpdoci(const char *s, const char *t)
{
  while (*s != '\0') {
    if (isdochar(*s) && isdochar(*t) && tolower(*s) != tolower(*t))
        return tolower(*s) - tolower(*t);
 
    s++;
    t++;
  }

  return *t == '\0' ? 0 : (tolower(*s) - tolower(*t));
}
