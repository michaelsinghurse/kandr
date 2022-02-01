#include <stdio.h>

#define MAXWIDTH 1000

void escape(char s[], char t[]);
void unescape(char r[], char s[]);

int main() {
  char t[] = "this\tis\tmy\tstring.\n";
  char s[MAXWIDTH];
  char r[MAXWIDTH];
  escape(s, t);
  unescape(r, s);
  printf("before: %s", t);
  printf("after: %s\n", s);
  printf("and back: %s", r);

  return 0;
}

void escape(char s[], char t[]) {
  int c, i, j;

  for (i = j = 0; (c = t[i]) != '\0'; ++i)
    switch (c) {
      case '\n':
        s[j++] = '\\';
        s[j++] = 'n';
        break;
      case '\t':
        s[j++] = '\\';
        s[j++] = 't';
        break;
      default:
        s[j++] = c;
        break;
    }

  s[j] = '\0';
}

void unescape(char r[], char s[]) {
  int c, i, j;

  for (i = j = 0; (c = s[i]) != '\0'; ++i)
    switch (c) {
      case 'n':
        if (i - 1 >= 0 && s[i-1] == '\\')
          r[j-1] = '\n';
        else
          r[j++] = c;
        break;
      case 't':
        if (i - 1 >= 0 && s[i-1] == '\\')
          r[j-1] = '\t';
        else
          r[j++] = c;
        break;
      default:
        r[j++] = c;
        break;
    }

  r[j] = '\0';
}

