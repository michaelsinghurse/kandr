#include <stdio.h>

#define LOWER 0
#define UPPER 300
#define STEP 20

/* print Fahrenheit-Celsius table
 * for Fahrenheit = 300, 280, ..., 0 
 */
int main() {
  printf("%s\n", "  F      C   ");
  printf("%s\n", "------|------");

  for (float fahr = UPPER; fahr >= LOWER; fahr -= STEP) {
    printf("%6.0f %6.1f\n", fahr, (5.0/9.0)*(fahr-32.0));
  }

  return 0;
}
