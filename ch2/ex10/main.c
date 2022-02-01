#include <stdio.h>

char lower(char c);

int main() {
  printf("%c => %c\n", 'A', lower('A'));
  printf("%c => %c\n", 'Z', lower('Z'));
  printf("%c => %c\n", 'a', lower('a'));
  printf("%c => %c\n", 'z', lower('z'));
  printf("%c => %c\n", '0', lower('0'));

  return 0;
}

char lower(char c) {
  return (c >= 'A' && c <= 'Z') ? c - ('A' - 'a') : c;
}
