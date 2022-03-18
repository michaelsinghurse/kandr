#include <stdio.h>
#include <stdlib.h>

#define TABWIDTH 4
#define MAXLINE 1000

int mygetline(char *, int);
void entab(char *, int, int);

/*
 * entab -m +n
 * tab stops every n columns starting at column m
 *
 */
int main(int argc, char *argv[]) {
  int len;
  char current[MAXLINE];
  int firstcol = TABWIDTH;
  int tabwidth = TABWIDTH;

  while (--argc > 0 && argv++)
    if ((*argv)[0] == '-')
      firstcol = atoi(++argv[0]);
    else if ((*argv)[0] == '+')
      tabwidth = atoi(++argv[0]);
    else {
      printf("invalid argument: %s\n", *argv);
      printf("usage: entab -m +n\n");
      return 1;
    }

  while ((len = mygetline(current, MAXLINE)) > 0) {
    entab(current, firstcol, tabwidth);
    printf("%s", current);
  }

  return 0;
}

void entab(char line[], int firstcol, int tabwidth) {
  int c;
  int i = 0;
  int j = 0;
  int num_spaces = 0;

  // 012345678901234567890
  //           a         b

  while ((c = line[i]) != '\0') {
    if (c == ' ' && num_spaces == 0) {
      num_spaces = 1;
    } else if (c == ' ' && num_spaces > 0) {
      num_spaces += 1;
    } else if (c != ' ' && num_spaces == 0) {
      line[j] = c;
      ++j;
    } else if (c != ' ' && num_spaces > 0) {
      int tabs_to_add;
      int spaces_to_add;

      if (j < firstcol && num_spaces >= tabwidth) {
        spaces_to_add = num_spaces;
        tabs_to_add = 0;
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
