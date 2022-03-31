#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define MAXNAME 100

int main(int argc, char **argv)
{
  char c, *pc, (*func)(char), name[MAXNAME];

  pc = strrchr(*argv, '/');
  strcpy(name, ++pc);

  if (strstr(name, "lower"))
    func = (char (*)(char)) tolower;
  else if (strstr(name, "upper"))
    func = (char (*)(char)) toupper;
  else {
    printf("invalid program name: %s\n", name);
    return 1;
  }

  while ((c = getchar()) != EOF)
    putchar((*func)(c));
  
  return 0;
}

