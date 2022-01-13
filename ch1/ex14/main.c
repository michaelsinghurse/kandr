#include <stdio.h>

#define COUNT 200

int main() {
  int c, i;
  int chars[COUNT];

  for (i = 0; i < COUNT; ++i)
    chars[i] = 0;

  while ((c = getchar()) != EOF)
    ++chars[c];

  for (i = 0; i < COUNT; ++i)
    if (chars[i] != 0)
      printf("'%c': %d\n", i, chars[i]);

  return 0;
}

