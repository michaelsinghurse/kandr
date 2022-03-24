#include <stdio.h>

#define BUFSIZE 100

static int buf[BUFSIZE];
static int *pbuf = buf;

int getch(void)
{
  if (pbuf > buf)
    return *--pbuf;
  else
    return getchar();
}

void ungetch(int c)
{
  if (pbuf - buf < BUFSIZE)
    *pbuf++ = c;
  else
    printf("ungetch: buffer full\n");
}
