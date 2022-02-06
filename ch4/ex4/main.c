#include <stdio.h>
#include <stdlib.h>

#define MAXOP   100
#define NUMBER  '0'

int getop(char []);
void push(double);
double pop(void);
void clear(void);

int main() {
  int type;
  double op1;
  double op2;
  char s[MAXOP];

  while ((type = getop(s)) != 'q' && type != 'Q') {
    switch (type) {
      case NUMBER:
        push(atof(s));
        break;
      case '+':
        push(pop() + pop());
        break;
      case '*':
        push(pop() * pop());
        break;
      case '-':
        op2 = pop();
        push(pop() - op2);
        break;
      case '/':
        op2 = pop();
        if (op2 != 0.0)
          push(pop() / op2);
        else
          printf("error: zero divisor\n");
        break;
      case '%':
        op2 = pop();
        push((float) ((int) pop() % (int) op2));
        break;
      case '\n':
        printf("\t%.8g\n", pop());
        break;
      case 'P':
        op2 = pop();
        printf("\t%.8g\n", op2);
        push(op2);
        break;
      case 'D':
        op2 = pop();
        push(op2);
        push(op2);
        break;
      case 'S':
        op2 = pop();
        op1 = pop();
        push(op2);
        push(op1);
        break;
      case 'C':
        clear();
        break;
      default:
        printf("error: unknown command: %s\n", s);
        break;
    }
  }

  return 0;
}

