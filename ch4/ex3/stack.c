#include <stdio.h>

#define STACKSIZE 100

int sp = 0;
double stack[STACKSIZE];

void push(double val) {
  if (sp < STACKSIZE)
    stack[sp++] = val;
  else
    printf("error: stack full, can't push %g\n", val);
}

double pop(void) {
  if (sp > 0)
    return stack[--sp];
  else {
    printf("error: stack empty\n");
    return 0.0;
  }
}

