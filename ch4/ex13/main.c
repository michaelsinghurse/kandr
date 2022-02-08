#include <stdio.h>

void reverse(char[]);

int main() {
  char a[] = "abcde";
  printf("%s\n", a);
  reverse(a);
  printf("%s\n", a);

  char b[] = "QRS TUV WXYZ";
  printf("%s\n", b);
  reverse(b);
  printf("%s\n", b);

  return 0;
}

void reverse(char s[]) {
  static int first_call = 1;
  static int i;
  static int j;
  int c;

  if (first_call) {
    i = 0;

    for (j = 0; s[j] != '\0'; ++j)
      ;

    j -= 1;
  }

  c = s[i];
  s[i] = s[j];
  s[j] = c;

  ++i;
  --j;
  first_call = 0;

  if (i < j)
    reverse(s);
  else
    first_call = 1;
}












