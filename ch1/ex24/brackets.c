#include <stdio.h>

int getindex(char x) {
  if (x == 'x')
    return 0;
  else
    return 1;
}

int main() {
  char arr[2];
  arr[0] = 'a';
  arr[1] = 'b';

  // within brackets you can have quotes and parens
  printf("%c\n", arr[getindex('x')]);

  // and they can wrap to a second line, apparently
  printf("%c\n", arr[1
  ]);

  return 0;
}
