#include <stdio.h>
#include <string.h>

#define MAXLINE 1000

/* compare two files, print first line of each where they differ */
int main(int argc, char **argv)
{
  int lineno, status;
  FILE *pf1, *pf2;
  char l1[MAXLINE], l2[MAXLINE];
  char *prog, *f1, *f2;

  prog = argv[0];

  if (argc != 3) {
    fprintf(stderr, "usage: %s file1 file2\n", prog);
    return 1;
  }

  f1 = argv[1];
  f2 = argv[2];

  if ((pf1 = fopen(f1, "r")) == NULL) {
    fprintf(stderr, "%s: can't open %s\n", prog, f1);
    return 1;
  }

  if ((pf2 = fopen(f2, "r")) == NULL) {
    fprintf(stderr, "%s: can't open %s\n", prog, f2);
    fclose(pf1);
    return 1;
  }

  lineno = 1;
  while (fgets(l1, MAXLINE, pf1) != NULL && fgets(l2, MAXLINE, pf2) != NULL) {
    if (strcmp(l1, l2) != 0) {
      printf("%s [%d]: %s", f1, lineno, l1);
      printf("%s [%d]: %s", f2, lineno, l2);
      break;
    }

    lineno++;
  }

  if (ferror(pf1)) {
    fprintf(stderr, "error reading %s\n", f1);
  } else if (feof(pf1) && !feof(pf2)) {
    printf("All of the lines in %s are the same as the first %d lines in %s\n",
           f1, lineno, f2);
  } else if (ferror(pf2)) {
    fprintf(stderr, "error reading %s\n", f2);
  } else if (!feof(pf1) && feof(pf2)) {
    printf("All of the lines in %s are the same as the first %d lines in %s\n",
           f2, lineno, f1);
  }

  status = (ferror(pf1) || ferror(pf2)) ? 1 : 0;

  fclose(pf1);
  fclose(pf2);

  return status;
}

