#include <stdio.h>

int main() {
  int c;

  c = getchar();

  printf("%d\n", c != EOF);

  c = EOF;

  printf("%d\n", c != EOF);

  printf("%d\n", EOF);

  return 0;
}
