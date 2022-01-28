#include <stdio.h>

int assertequal(int a, int b);
int htoi(const char s[]);

int main() {
  int pass;
  char a[] = "0x001";
  int aint = 1;
  char b[] = "0X001";
  int bint = 1;
  char c[] = "0X000";
  int cint = 0;
  char d[] = "1";
  int dint = 1;
  char e[] = "0";
  int eint = 0;
  char f[] = "0x011";
  int fint = 17;
  char g[] = "0X011";
  int gint = 17;
  char h[] = "111";
  int hint = 273;
  char i[] = "0x100";
  int iint = 256; 
  char j[] = "0x123";
  int jint = 291;
  char k[] = "0x00000000000000000000001";
  int kint = 1;

  printf("Converts %s to %d? ", a, aint);
  pass = assertequal(htoi(a), aint);
  if (pass)
    printf("%s\n", "PASS");
  else
    printf("%s\n", "FAIL");

  printf("Converts %s to %d? ", b, bint);
  pass = assertequal(htoi(b), bint);
  if (pass)
    printf("%s\n", "PASS");
  else
    printf("%s\n", "FAIL");

  printf("Converts %s to %d? ", c, cint);
  pass = assertequal(htoi(c), cint);
  if (pass)
    printf("%s\n", "PASS");
  else
    printf("%s\n", "FAIL");

  printf("Converts %s to %d? ", d, dint);
  pass = assertequal(htoi(d), dint);
  if (pass)
    printf("%s\n", "PASS");
  else
    printf("%s\n", "FAIL");

  printf("Converts %s to %d? ", e, eint);
  pass = assertequal(htoi(e), eint);
  if (pass)
    printf("%s\n", "PASS");
  else
    printf("%s\n", "FAIL");

  printf("Converts %s to %d? ", f, fint);
  pass = assertequal(htoi(f), fint);
  if (pass)
    printf("%s\n", "PASS");
  else
    printf("%s\n", "FAIL");

  printf("Converts %s to %d? ", g, gint);
  pass = assertequal(htoi(g), gint);
  if (pass)
    printf("%s\n", "PASS");
  else
    printf("%s\n", "FAIL");

  printf("Converts %s to %d? ", h, hint);
  pass = assertequal(htoi(h), hint);
  if (pass)
    printf("%s\n", "PASS");
  else
    printf("%s\n", "FAIL");

  printf("Converts %s to %d? ", i, iint);
  pass = assertequal(htoi(i), iint);
  if (pass)
    printf("%s\n", "PASS");
  else
    printf("%s\n", "FAIL");

  printf("Converts %s to %d? ", j, jint);
  pass = assertequal(htoi(j), jint);
  if (pass)
    printf("%s\n", "PASS");
  else
    printf("%s\n", "FAIL");

  printf("Converts %s to %d? ", k, kint);
  pass = assertequal(htoi(k), kint);
  if (pass)
    printf("%s\n", "PASS");
  else
    printf("%s\n", "FAIL");

  return 0;
}

int htoi(const char hex[]) {
  char c;
  int i;
  int d;
  int result = 0;

  if (hex[0] == '0' && (hex[1] == 'x' || hex[1] == 'X'))
    i = 2;
  else
    i = 0;

  while ((c = hex[i]) != '\0') {
    if (c >= '0' && c <= '9')
      d = c - '0';
    else if (c >= 'a' && c <= 'f')
      d = 10 + c - 'a';
    else if (c >= 'A' && c <= 'F')
      d = 10 + c - 'A';
    else
      // invalid character
      return -1; 

    result = 16 * result + d;
    ++i;
  }

  return result;
}

int assertequal(int a, int b) {
  return a == b;
}
