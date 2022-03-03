#include <stdio.h>

char *mystrncpy(char *, char *, int);
char *mystrncat(char *, char *, int);
int mystrncmp(char *, char *, int);

int main(int argc, char *argv[])
{
  char a[20];
  char *b = "abcdef";
  printf("strncpy expected 'a', actual '%s'\n", mystrncpy(a, b, 1));
  printf("strncpy expected 'abc', actual '%s'\n", mystrncpy(a, b, 3));
  printf("strncpy expected 'abcdef', actual '%s'\n", mystrncpy(a, b, 30));

  printf("\n");

  char c[20];
  c[0] = 'a';
  c[1] = 'b';
  c[2] = 'c';
  c[3] = '\0';
  char *d = "defghijk";
  printf("strncat expected 'abc', actual '%s'\n", mystrncat(c, d, 0));
  printf("strncat expected 'abcd', actual '%s'\n", mystrncat(c, d, 1));
  c[3] = '\0';
  printf("strncat expected 'abcdef', actual '%s'\n", mystrncat(c, d, 3));
  c[3] = '\0';
  printf("strncat expected 'abcdefhijk', actual '%s'\n", mystrncat(c, d, 30));

  printf("\n");

  char *e = "abcdef";
  char *f = "abcxyz";
  char *g = "A";
  printf("strncmp expected '=0', actual '%d'\n", mystrncmp(e, f, 1));
  printf("strncmp expected '=0', actual '%d'\n", mystrncmp(e, f, 3));
  printf("strncmp expected '<0', actual '%d'\n", mystrncmp(e, f, 30));
  printf("strncmp expected '>0', actual '%d'\n", mystrncmp(e, g, 30));

  return 0;
}

char *mystrncpy(char *s, char *t, int n)
{
  int i;

  i = 0;
  while (*s++ = *t++)
  {
    i++;

    if (i >= n)
    {
      *s++ = '\0';
      break;
    }
  }

  return s - i - 1; 
}

char *mystrncat(char *s, char *t, int n)
{
  char *ps = s;

  while (*s)
    s++;

  while (n > 0 && (*s = *t)) {
    n--;
    s++;
    t++;
  }

  if (n == 0)
    *s = '\0';

  return ps;
}

int mystrncmp(char *s, char *t, int n)
{
  if (n == 0)
    return 0;

  for ( ; n > 0 && *s == *t; n--, s++, t++)
    if (*s == '\0')
      return 0;

  return n == 0 ? 0 : (*s - *t);
}

