#include <stdio.h>

int strend(char *, char *);

int main(int argc, char *argv[])
{
  char *a = "hello, world!";
  char *b = "world!";
  char *c = "foo";
  char *d = "";

  printf("Does '%s' end with '%s'? %s\n", a, b, strend(a, b) ? "Yes" : "No");
  printf("Does '%s' end with '%s'? %s\n", a, c, strend(a, c) ? "Yes" : "No");
  printf("Does '%s' end with '%s'? %s\n", a, d, strend(a, d) ? "Yes" : "No");

  return 0;
}

int strcmp(char *s, char *t)
{
  for ( ; *s == *t; s++, t++)
    if (*s == '\0')
      return 0;

  return *s - *t;
}

int mystrlen(char *s)
{
  int n;

  for (n = 0; *s != '\0'; ++n, ++s)
    ;

  return n;
}

int strend(char *s, char *t)
{
  // return 0 if either is empty 
  if (*s == '\0' || *t == '\0')
    return 0;

  int len_s, len_t;

  len_s = mystrlen(s);
  len_t = mystrlen(t);

  // if t is longer than s, return 0
  if (len_t > len_s)
    return 0;

  return strcmp(s+len_s-len_t, t) == 0;
}

