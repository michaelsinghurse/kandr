#include <stdio.h>

#define TABWIDTH 4
#define MAXLINE 1000

int mygetline(char s[], int m);
void entab(char s[], int t);

int main() {
  int len;
  char current[MAXLINE];

  while ((len = mygetline(current, MAXLINE)) > 0) {
    entab(current, TABWIDTH);
    printf("%s", current);
  }

  return 0;
}

int mygetline(char line[], int maxwidth) {
  int c, i;

  for (i = 0; i < maxwidth - 1 && (c = getchar()) != EOF && c != '\n'; ++i)
    line[i] = c;

  if (c == '\n') {
    line[i] = c;
    ++i;
  }

  line[i] = '\0';

  return i;
}

void entab(char line[], int tabwidth) {
  int c;
  int i = 0;
  int j = 0;
  int num_spaces = 0;

  while ((c = line[i]) != '\0') {
    if (c == ' ' && num_spaces == 0) {
      num_spaces = 1;
    } else if (c == ' ' && num_spaces > 0) {
      num_spaces += 1;
    } else if (c != ' ' && num_spaces == 0) {
      line[j] = c;
      ++j;
    } else if (c != ' ' && num_spaces > 0) {
      int tabs_to_add = num_spaces / tabwidth;
      int spaces_to_add = num_spaces % tabwidth;

      while (tabs_to_add > 0) {
        line[j] = '\t';
        --tabs_to_add;
        ++j;
      }

      while (spaces_to_add > 0) {
        line[j] = ' ';
        --spaces_to_add;
        ++j;
      }

      line[j] = c;
      ++j;
      num_spaces = 0;
    }

    ++i;
  }

  line[j] = '\0';
}

