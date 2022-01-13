#include <stdio.h>

#define MIN 0
#define MAX 120
#define STEP 10

float to_celsius(int fahr);

int main() {
  printf("Fahr  Cels\n");

  for (int fahr = MIN; fahr <= MAX; fahr += STEP)
    printf(" %3d: %3.1f\n", fahr, to_celsius(fahr));

  return 0;
}

float to_celsius(int fahr) {
  return (5.0 / 9.) * (fahr - 32.0);
}
