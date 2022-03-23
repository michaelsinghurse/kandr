#include <stdio.h>

#define BUFSIZE 100

char buf[BUFSIZE];
char *pbuf;

char getch(void)
{
  if (pbuf > buf)
    return *--pbuf;
  else
    return getchar();
}

void ungetch(char c)
{
  if (pbuf - buf < BUFSIZE)
    *pbuf++ = c;
  else
    printf("ungetch: buffer full\n");
}
