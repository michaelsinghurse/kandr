#include <stdio.h>
#include <ctype.h>

int mygetline(char *, int);
int atoi(char *);
void reverse(char *);
void itoa (int, char *);

/*
 * strindex (ch 4)
 * getop (ch 4)
 */

#define MAXLINE 1000

int main(int argc, char *argv[])
{
  /*
  // TEST mygetline
  char s[MAXLINE];

  while (mygetline(s, MAXLINE) > 0)
    printf("%s", s);
  */
  
  /*
  // TEST atoi
  printf("atoi non-digit returns 0: %d\n", atoi("four"));
  printf("atoi 123: %d\n", atoi("123"));
  printf("atoi 123.45: %d\n", atoi("123.45"));
  printf("atoi -123: %d\n", atoi("-123"));
  */

  /*
  // TEST itoa
  char s[20];

  int n = 123;
  itoa(n, s);
  printf("itoa on %d produces %s\n", n, s);

  n = -123;
  itoa(n, s);
  printf("itoa on %d produces %s\n", n, s);

  n = 0;
  itoa(n, s);
  printf("itoa on %d produces %s\n", n, s);
  */

  return 0;
}

void itoa(int n, char *s)
{
  int sign;
  char *ps;

  ps = s;

  sign = 1;
  if (n < 0) {
    sign = -1;
    n *= -1;
  }
  
  do {
    *s++ = n % 10 + '0';
  } while ((n /= 10) > 0);

  if (sign < 0)
    *s++ = '-';

  *s = '\0';

  reverse(ps);
}

void reverse(char *s)
{
  char c;
  char *l, *r;

  l = s;

  while (*s != '\0')
    s++;

  r = s-1;

  while (l < r)
  {
    c = *l;
    *l = *r;
    *r = c;
    l++;
    r--;
  }
}

int atoi(char *s)
{
  int n, sign;

  while (isspace(*s))
    s++;

  sign = (*s == '-') ? -1 : 1;

  if (*s == '+' || *s == '-')
    s++;

  n = 0;
  while (isdigit(*s))
  {
    n = 10 * n + (*s - '0'); 
    s++;
  }

  return sign * n;
}

int mygetline(char *s, int lim)
{
  char c;
  char *ps;

  ps = s;

  while (lim-- > 0 && (c = getchar()) != EOF && c != '\n')
    *s++ = c;

  if (c == '\n')
    *s++ = c;

  *s = '\0';

  return s - ps;
}
