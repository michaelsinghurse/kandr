#include <stdio.h>

#define IN 1
#define OUT 0

int is_word_char(int c) {
  return c != ' ' && c != '\t' && c != '\n';
}

int main() {
  int c;
  int state = OUT;

  while ((c = getchar()) != 'X') {
    if (is_word_char(c)) {
      printf("%c", c);
      
      if (state == OUT)
        state = IN;
    } else if (state == IN) {
      state = OUT;
      printf("\n");
    }
  }

  printf("\n");

  return 0;
}
