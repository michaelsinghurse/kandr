#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>

#define MAXBUF 100

void push(double);
double pop(void);

int main(int argc, char *argv[])
{
  double l, r;

  while (argc-- > 1 && argv++) {
    if (isdigit((*argv)[0]) || ((*argv)[0] == '-' && isdigit((*argv)[1]))) {
      push(atof(*argv));
      continue;
    }
    
    r = pop();
    l = pop();

    switch ((*argv)[0]) {
      case '+':
        push(l + r);
        break;
      case '-':
        push(l - r);
        break;
      case '*':
        push(l * r);
        break;
      case '/':
        push(l / r);
        break;
      default:
        printf("error: invalid token %s\n", *argv);
    }
  }
  
  printf("%f\n", pop());

  return 0;
}

double buf[MAXBUF];
double *pbuf = buf;

void push(double d)
{
  if (pbuf - buf < MAXBUF)
    *pbuf++ = d;
  else
    printf("error: no room in buffer\n");
}

double pop()
{
  if (pbuf > buf)
    return *--pbuf;
  else
    printf("error: empty buffer\n");
}
