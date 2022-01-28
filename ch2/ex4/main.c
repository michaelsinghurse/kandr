#include <stdio.h>

int includes(char c, char s[]);
void squeeze(char s[], char t[]);

int main() {
  char a[] = "banana";
  char b[] = "a";
  printf("remove all {%s} from %s => ", b, a);
  squeeze(a, b); 
  printf("%s\n", a);

  char c[] = "United States of America";
  char d[] = "aeiou";
  printf("remove all {%s} from %s => ", d, c);
  squeeze(c, d); 
  printf("%s\n", c);

  char e[] = "Mississippi";
  char f[] = "sp";
  printf("remove all {%s} from %s => ", f, e);
  squeeze(e, f); 
  printf("%s\n", e);
 
  return 0;
}

int includes(char needle, char haystack[]) {
  int c, i; 

  for (i = 0; (c = haystack[i]) != '\0'; ++i)
    if (c == needle)
      return 1;

  return 0;
}

void squeeze(char s[], char t[]) {
  int i, j;

  for (i = j = 0; s[i] != '\0'; ++i)
    if (!includes(s[i], t))
      s[j++] = s[i];
  
  s[j] = '\0';
}
