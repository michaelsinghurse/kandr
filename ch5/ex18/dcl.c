#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAXTOKEN 100

enum { NAME, PARENS, BRACKETS };

void dcl(void);
void dirdcl(void);
int gettoken(void);

int tokentype;
char line[MAXTOKEN * 10];
char *pl = line;
char token[MAXTOKEN];
char name[MAXTOKEN];
char datatype[MAXTOKEN];
char out[MAXTOKEN * 10];

/* dcl: convert declaration to word description */
/*
 * TODO:
 * x skip empty lines '\n\0'
 * - "Make dcl recover from input errors" => Just say invalid input and write
 *   the input and move to the next line
 */
int main(int argc, char **argv)
{
  while (gettoken() != EOF) {
    if (tokentype == '\n') {
      pl = line;
      continue;
    }

    strcpy(datatype, token);
    out[0] = '\0';
    dcl();

    if (tokentype != '\n') {
      *pl = '\0';
      printf("invalid declaration: %s\n", line);
      pl = line;
      continue;
    }

    printf("%s: %s %s\n", name, out, datatype);
    pl = line;
  }

  return 0;
}

void dcl(void)
{
  int ns;

  for (ns = 0; gettoken() == '*'; )
    ns++;

  dirdcl();

  while (ns-- > 0)
    strcat(out, " pointer to");
}

void dirdcl(void)
{
  int type;

  if (tokentype == '(') {
    dcl();
    if (tokentype != ')')
      printf("error: missing )\n");
  } else if (tokentype == NAME)
    strcpy(name, token);
  else
    printf("error: expected name or (dcl)\n");

  while ((type = gettoken()) == PARENS || type == BRACKETS)
    if (type == PARENS)
      strcat(out, " function returning");
    else {
      strcat(out, " array");
      strcat(out, token);
      strcat(out, " of");
    }
}

int gettoken(void)
{
  int c, getch(void);
  void ungetch(int);
  char *pt = token;
  
  while ((c= getch()) == ' ' || c == '\t')
    *pl++ = c;

  if (c == '(') {
    if ((c = getch()) == ')') {
      strcpy(token, "()");
      *pl++ = '(';
      *pl++ = ')';
      return tokentype = PARENS;
    } else {
      *pl++ = '(';
      ungetch(c);
      return tokentype = '(';
    }
  } else if (c == '[') {
    *pt++ = c;
    *pl++ = c;
    while ((c = getch()) != ']') {
      *pt++ = c;
      *pl++ = c;
    }
    *pt++ = c;
    *pl++ = c;
    *pt = '\0';
    return tokentype = BRACKETS;
  } else if (isalpha(c)) {
    *pt++ = c;
    *pl++ = c;
    while (isalnum(c = getch())) {
      *pt++ = c;
      *pl++ = c;
    }
    *pt = '\0';
    ungetch(c);
    return tokentype = NAME;
  } else {
    *pl++ = c;
    return tokentype = c;
  }
}

