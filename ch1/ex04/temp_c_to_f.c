#include <stdio.h>

/* print Celsius-Fahrenheit table
 * for Celsius = 0, 20, ..., 300
 */
int main() {
  float fahr, celsius;

  int lower = -20;
  int upper = 100;
  int step = 10;

  printf("%s\n", "  C      F   ");
  printf("%s\n", "------|------");

  celsius = lower;
  while (celsius <= upper) {
    fahr = ((9.0 / 5.0) * celsius) + 32.0;
    
    printf("%6.0f %6.1f\n", celsius, fahr);

    celsius += step;
  }

  return 0;
}
