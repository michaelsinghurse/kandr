#include <stdio.h>

void mystrcat(char *, char *);

int main() {
  char a[100];
  a[0] = 'a';
  a[1] = 'b';
  a[2] = 'c';
  a[3] = '\0';
  char b[] = "def";

  mystrcat(a, b);

  printf("%s\n", a);

  return 0;
}

void mystrcat(char *s, char *t) {
  while (*s != '\0')
    *s++;

  while (*s++ = *t++)
    ;
}
