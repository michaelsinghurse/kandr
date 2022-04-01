#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv)
{
  FILE *fp;
  void filecopy(FILE *, FILE *);
  char *prog = *argv;

  if (argc == 1)
    filecopy(stdin, stdout);
  else
    while (argc-- > 1) {
      if ((fp = fopen(*++argv, "r")) == NULL) {
        fprintf(stderr, "%s: can't open %s\n", prog, *argv);
        exit(1);
      }

      filecopy(fp, stdout);
      fclose(fp);
    }

  if (ferror(stdout)) {
    fprintf(stderr, "%s: error writing stdout\n", prog);
    exit(2);
  }

  exit(0);
}

void filecopy(FILE *pfin, FILE *pfout)
{
  char c;

  while ((c = getc(pfin)) != EOF)
    putc(c, pfout);
}

