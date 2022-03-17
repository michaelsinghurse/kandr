#include <stdio.h>
#include <stdlib.h>

#define TABWIDTH 4
#define MAXLINE 1000

int mygetline(char s[], int m);
void entab(char s[], int t[], int m, int n);

int main(int argc, char *argv[]) {
  int i, len;
  char current[MAXLINE];
  int tabstops[MAXLINE];

  i = 1;
  while (i < argc) {
    if ((tabstops[i-1] = atoi(argv[i])) == 0) {
      printf("error: invalid tabstop: %s\n", argv[i]);
      return 1;
    }
    i++;
  }

  while ((len = mygetline(current, MAXLINE)) > 0) {
    entab(current, tabstops, i-1, TABWIDTH);
    printf("%s", current);
  }

  return 0;
}

void entab(char line[], int tabstops[], int numtabs, int tabwidth) {
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
      int tabs_to_add = 0;
      int spaces_to_add = 0;

      if (numtabs > 0 && j < tabstops[numtabs-1]) {
        int last_tab = 0;

        for (int k = 0; k < numtabs; k++)
          if (tabstops[k] > j && tabstops[k] <= i) {
            tabs_to_add += 1;
            last_tab = tabstops[k];
          }

        if (last_tab > j)
          spaces_to_add = i - last_tab;
        else
          spaces_to_add = i - j;

      } else {
        tabs_to_add = num_spaces / tabwidth;
        spaces_to_add = num_spaces % tabwidth;
      }

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

