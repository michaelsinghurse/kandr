#include <stdio.h>

int strend(char *, char *);

int main() {
  char a[] = "hello, world";
  char b[] = "world";

  printf("Does '%s' end with '%s'?\n", a, b);
  if (strend(a, b) == 1)
    printf("Yes it does!\n");
  else
    printf("No it does not.\n");

  char c[] = "foo bar";
  char d[] = "foo bar baz";

  printf("Does '%s' end with '%s'?\n", c, d);
  if (strend(c, d) == 1)
    printf("Yes it does!\n");
  else
    printf("No it does not.\n");
  return 0;
}

int strend(char *s, char *t) {
  // get the length of s
  int len_s, len_t;

  for (len_s = 0; *(s+len_s) != '\0'; ++len_s)
    ;

  // get the length of t
  for (len_t = 0; *(t+len_t) != '\0'; ++len_t)
    ;

  // if the length of t is greater than s, return 0
  if (len_t > len_s)
    return 0;

  // start at s[len_s - len_t] and t[0]
  s += len_s - len_t;

  // walk down the strings and compare chars
  while (*s++ == *t++)
    // if the chars are '\0' return 1
    if (*s == '\0')
      return 1;

  // if the chars are not the same return 0
  return 0;
}
