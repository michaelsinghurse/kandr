#include <stdio.h>

#define IN 1
#define OUT 0

/*
 * toy version of `wc`
 *
 * to test, I would use empty inputs, consecutive
 * newlines or spaces or tabs, perhaps a file with
 * only those characters. I would also try to overflow
 * the `nc` int with a large file. Perhaps try files
 * where characters are 16 bit or 8 bit etc.
 */
int main() {
  int nc = 0;
  int nw = 0;
  int nl = 0;
  int state = OUT;
  int c;

  while ((c = getchar()) != 'X') {
    ++nc;

    if (c == '\n')
      ++nl;

    if (c == ' ' || c == '\t' || c == '\n')
      state = OUT;
    else if (state == OUT) {
      state = IN;
      ++nw;
    }
  }

  printf("%d %d %d\n", nl, nw, nc);

  return 0;
}
