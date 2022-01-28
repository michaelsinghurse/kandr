#include <stdio.h>

int includes(char c, char s[]);
int any(char s1[], char s2[]);

int main() {
  char a[] = "Mississippi";
  char b[] = "aeiou";
  printf("The first index of {%s} in %s is %d.\n",
      b, a, any(a, b));

  char c[] = "Washington";
  char d[] = "aeiou";
  printf("The first index of {%s} in %s is %d.\n",
      d, c, any(c, d));

  char e[] = "Pullman";
  char f[] = "xyz";
  printf("The first index of {%s} in %s is %d.\n",
      f, e, any(e, f));

  char g[] = "Alabama";
  char h[] = "m";
  printf("The first index of {%s} in %s is %d.\n",
      h, g, any(g, h));

  return 0;
}

int includes(char needle, char haystack[]) {
  int i;

  for (i = 0; haystack[i] != '\0'; ++i)
    if (needle == haystack[i])
      return 1;

  return 0;
}

int any(char s1[], char s2[]) {
  int i;

  for (i = 0; s1[i] != '\0'; ++i)
    if (includes(s1[i], s2))
      return i;

  return -1;
}
