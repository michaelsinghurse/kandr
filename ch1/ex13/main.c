#include <stdio.h>

#define MAX 20
#define IN 1
#define OUT 0

int is_white_space(int c) {
  return c == ' ' || c == '\t' || c == '\n';
}

int main() {
  int c, i;
  int state = OUT;
  int lengths[MAX];

  for (i = 0; i < MAX; ++i)
    lengths[i] = 0;

  while ((c = getchar()) != EOF) {
    int ws = is_white_space(c);

    if (ws && state == IN) {
      state = OUT;
      ++lengths[i - 1];
    } else if (!ws && state == IN)
      ++i;
    else if (!ws && state == OUT) {
      state = IN;
      i = 1;
    }
  }

  printf("Length Count\n");

  for (i = 0; i < MAX; ++i) {
    int count = lengths[i];

    printf("%6d ", i + 1);

    for (int j = 0; j < count; ++j)
      printf("#");

    printf("\n");
  }

  return 0;
}

