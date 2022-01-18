#include <stdio.h>

#define FOLDWIDTH 80
#define MAXLINE 1000

int mygetline(char s[], int m);
int fold(char s[], char t[], int m);
void copy(char s[], char t[]);

int main() {
  int len;
  char current[MAXLINE];
  char extra[MAXLINE - FOLDWIDTH];

  while (mygetline(current, MAXLINE) > 0)
    do {
      len = fold(current, extra, FOLDWIDTH);

      printf("%s", current);

      copy(extra, current);
    } while (len > 0);

  return 0;
}


int mygetline(char line[], int maxwidth) {
  int c, i;

  for (i = 0; i < maxwidth && (c = getchar()) != EOF && c != '\n'; ++i)
    line[i] = c;

  if (c == '\n') {
    line[i] = c;
    ++i;
  }

  line[i] = '\0';

  return i;
}

/*
 * foldwidth = 4
 * 0123456789
 * abcNdefghi0
 *
 * 0123456789
 * defghi0
 *
 * len_line = 10
 *
 * i = 3
 * line[i] = ' ' 
 * line[3] = '\n'
 * line_end_index = 4
 *
 * i = 4
 * line[i] = 'd'
 */
int fold(char line[], char extra[], int foldwidth) {
  int i, j;
  int len_line = 0;

  while (line[len_line] != '\0')
    ++len_line;

  if (len_line <= foldwidth)
    return 0;

  // i is the index of the last space before the fold
  // TODO: handle case when there are no spaces before fold
  for (i = foldwidth - 1; line[i] != ' ' && line[i] != '\t' && line[i] != '\n'; --i) ;

  if (line[i] != '\n')
    line[i] = '\n';

  int line_end_idx = i + 1;

  // i is the first non-space after the fold
  // TODO: handle case when its all spaces after the fold
  for (i = i + 1; line[i] != ' ' && line[i] != '\t' && line[i] != '\n'; ++i) ;

  for (j = 0; line[i] != '\0'; ++j) {
    extra[j] = line[i];
    ++i;
  }

  line[line_end_idx] = '\0';
  extra[j] = '\0';

  return j;
}

void copy(char from[], char to[]) {
  int i;

  for (i = 0; from[i] != '\0'; ++i)
    to[i] = from[i];

  to[i] = '\0';
}


