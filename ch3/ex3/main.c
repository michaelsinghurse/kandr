#include <stdio.h>

#define MAXLINE 1000

void expand(char a[], char b[]);

int main() {
  char a[] = "a-z";
  char b[MAXLINE];
  expand(a, b);
  printf("before: %s\n", a);
  printf("after: %s\n", b);

  char c[] = "M-T";
  char d[MAXLINE];
  expand(c, d);
  printf("before: %s\n", c);
  printf("after: %s\n", d);

  char e[] = "0-9";
  char f[MAXLINE];
  expand(e, f);
  printf("before: %s\n", e);
  printf("after: %s\n", f);

  char g[] = "My children's names begin with the letters "
    "C-L and their ages are 2-7.";
  char h[MAXLINE];
  expand(g, h);
  printf("before: %s\n", g);
  printf("after: %s\n", h);

  char i[] = "a-b-c";
  char j[MAXLINE];
  expand(i, j);
  printf("before: %s\n", i);
  printf("after: %s\n", j);

  char k[] = "a-z0-9";
  char l[MAXLINE];
  expand(k, l);
  printf("before: %s\n", k);
  printf("after: %s\n", l);

  return 0;
}

int myislower(char c) {
  return c >= 'a' && c <= 'z';
}

int myisupper(char c) {
  return c >= 'A' && c <= 'Z';
}

int myisdigit(char c) {
  return c >= '0' && c <= '9';
}

void expand(char a[], char b[]) {
  int c, d, i, j;

  for (i = j = 0; (c = a[i]) != '\0'; ++i)
    if (c == '-' && i-1 >= 0 && a[i+1] != '\0' && (
        (myislower(a[i-1]) && myislower(a[i+1])) ||
        (myisupper(a[i-1]) && myisupper(a[i+1])) ||
        (myisdigit(a[i-1]) && myisdigit(a[i+1]))))
      for (d = a[i-1] + 1; d < a[i+1]; ++d)
        b[j++] = d;
    else
      b[j++] = c;

  b[j] = '\0';
}

