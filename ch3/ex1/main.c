#include <stdio.h>

int binsearch(int x, int v[], int n);

int main() {
  int len = 6;
  int a[len];
  a[0] = 0;
  a[1] = 1;
  a[2] = 2;
  a[3] = 3;
  a[4] = 4;
  a[5] = 5;

  printf("should be %d: %d\n", 3, binsearch(3, a, len));
  printf("should be %d: %d\n", -1, binsearch(6, a, len));

  len = 5;
  int b[len];
  b[0] = 100;
  b[1] = 200;
  b[2] = 201;
  b[3] = 202;
  b[4] = 100000;

  printf("should be %d: %d\n", 0, binsearch(100, b, len));
  printf("should be %d: %d\n", 4, binsearch(100000, b, len));

  return 0;
}

// SOLUTION TO PROBLEM
int binsearch(int needle, int haystack[], int len) {
  int low, mid, high;

  low = 0;
  high = len - 1;
  mid = (low + high) / 2;

  while (low <= high && haystack[mid] != needle) {
    if (haystack[mid] < needle)
      low = mid + 1;
    else
      high = mid -1;

    mid = (low + high) / 2;
  }

  if (haystack[mid] == needle)
    return mid;
  else
    return -1;
}

/*
// ORIGINAL IMPLEMENTATION
int binsearch(int needle, int haystack[], int len) {
  int low, mid, high;

  low = 0;
  high = len - 1;

  while (low <= high) {
    mid = (low + high) / 2;

    if (haystack[mid] < needle)
      low = mid + 1;
    else if (haystack[mid] > needle)
      high = mid -1;
    else
      return mid;
  }

  return -1;
}
*/

