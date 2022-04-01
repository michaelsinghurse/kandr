#include <stdio.h>

int main(int argc, char **argv)
{
  FILE *fp;
  void filecopy(FILE *, FILE *);

  if (argc == 1)
    filecopy(stdin, stdout);
  else
    while (argc-- > 1) {
      if ((fp = fopen(*++argv, "r")) == NULL) {
        printf("cat: can't open %s\n", *argv);
        return 1;
      }

      filecopy(fp, stdout);
      fclose(fp);
    }

  return 0;
}

void filecopy(FILE *pfin, FILE *pfout)
{
  char c;

  while ((c = getc(pfin)) != EOF)
    putc(c, pfout);
}

