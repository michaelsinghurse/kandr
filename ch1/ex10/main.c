#include <stdio.h>

int main() {
  int c;

  while ((c = getchar()) != EOF) {
    if (c == '\b') {
      putchar('\\');
      putchar('b');
      continue;
    } 

    if (c == '\t') {
      putchar('\\');
      putchar('t');
      continue;
    } 

    if (c == '\\') {
      putchar('\\');
      putchar('\\');
      continue;
    }

    putchar(c);
  }

  return 0;
}
