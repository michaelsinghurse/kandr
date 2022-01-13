#include <stdio.h>

int main() {
  int c;
  int is_blank = 0;

  while ((c = getchar()) != EOF) {
    if (c == ' ') {
      if (is_blank == 0) {
        is_blank = 1;
        putchar(c);
      }
    } else {
      is_blank = 0;
      putchar(c);
    }
  }

  return 0;
}
