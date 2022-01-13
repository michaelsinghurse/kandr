#include <stdio.h>

#define MY_EOL 'X'

int main() {
  int c;
  
  int num_blanks = 0;
  int num_tabs = 0;
  int num_newlines = 0;

  while ((c = getchar()) != MY_EOL) {
    if (c == ' ')
      ++num_blanks;
    else if (c == '\t')
      ++num_tabs;
    else if (c == '\n')
      ++num_newlines;
  }

  printf("Number of blanks:\t%d\n", num_blanks);
  printf("Number of tabs:\t\t%d\n", num_tabs);
  printf("Number of newlines:\t%d\n", num_newlines);

  return 0;
}
