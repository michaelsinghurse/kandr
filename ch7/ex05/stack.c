#include <stdio.h>

#define STACKSIZE 100

double stack[STACKSIZE];
double *sp = stack;

void push(double val) {
  if (sp - stack < STACKSIZE)
    *sp++ = val;
  else
    printf("error: stack full, can't push %g\n", val);
}

double pop(void) {
  if (sp - stack > 0)
    return *--sp;
  else {
    printf("error: stack empty\n");
    return 0.0;
  }
}

