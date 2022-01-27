#include <stdio.h>
#include <limits.h>
#include <float.h>

int main() {
  printf("Type\t\t\tMin\t\tMax\n");
  printf("unsigned char\t\t%d\t\t%d\n", 0, UCHAR_MAX);
  printf("signed char\t\t%d\t\t%d\n", SCHAR_MIN, SCHAR_MAX);
  printf("unsigned short\t\t%hu\t\t%hu\n", 0, USHRT_MAX);
  printf("signed short\t\t%hd\t\t%hd\n", SHRT_MIN, SHRT_MAX);
  printf("unsigned int\t\t%u\t\t%u\n", 0, UINT_MAX);
  printf("signed int\t\t%d\t%d\n", INT_MIN, INT_MAX);
  printf("unsigned long\t\t%u\t\t%lu\n", 0, ULONG_MAX);
  printf("signed long\t\t%ld\t%ld\n", LONG_MIN, LONG_MAX);
  printf("float\t\t\t%f\t%f\n", FLT_MIN, FLT_MAX);
  printf("double\t\t\t%f\t%f\n", DBL_MIN, DBL_MAX);

  return 0;
}
