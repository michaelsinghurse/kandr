#include <stdio.h>

void mystrcat(char *, char *);

int main(int argc, char *argv[])
{
  char a[100];
  a[0] = 'h';
  a[1] = 'e';
  a[2] = 'l';
  a[3] = 'l';
  a[4] = 'o';
  a[5] = ',';
  a[6] = '\0';
  char *b = " world!";

  mystrcat(a, b);
  printf("%s\n", a);
  
  char c[10];
  c[0] = '\0';
  char *d = "hi";

  mystrcat(c, d);
  printf("%s\n", c);

  return 0;
}

void mystrcat(char *s, char *t)
{
  for ( ; *s != '\0'; *s++)
    ;

  while (*s++ = *t++)
    ;
}
