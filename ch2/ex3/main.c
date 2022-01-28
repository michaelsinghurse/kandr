#include <stdio.h>

char[] assertequal(int a, int b);
int htoi(const char s[]);

int main() {
  char a[] = "0x001";
  int aint = 1;
  char b[] = "0X001";
  int bint = 1;
  char c[] = "001";
  int cint = 1;
  char d[] = "1";
  int dint = 1;
  char e[] = "0";
  int eint = 0;
  char f[] = "0x011";
  int fint = 17;
  char g[] = "0X011";
  int gint = 17;
  char h[] = "011";
  int hint = 17;
  char i[] = "0x100";
  int iint = 256; 
  char j[] = "0x123";
  int jint = 291;
  char k[] = "0x00000000000000000000001";
  int kint = 1;

  printf("Converts %s to %d? %s\n", a, aint, assertequal(htoi(a), aint)); 


    

  return 0;
}

int htoi(const char hex[]) {
  return 1;
}

char[] assertequal(int a, int b) {
  if (a == b)
    return "PASS";
  else
    return "FAIL";
}
