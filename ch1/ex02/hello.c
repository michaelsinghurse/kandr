#include <stdio.h>

int main()
{
  printf("a: ");
  printf("hello\aworld\n");
  printf("b: ");
  printf("hello\bworld\n");
  printf("e: ");
  printf("hello\eworld\n");
  printf("f: ");
  printf("hello\fworld\n");
  printf("n: ");
  printf("hello\nworld\n");
  printf("r: ");
  printf("hello\rworld\n");
  printf("t: ");
  printf("hello\tworld\n");
  printf("u: ");
  printf("hello\u1F600world\n");
  printf("hello\vworld\n");
  printf("hello\x1world\n");

  return 0;
}
