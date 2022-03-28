#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAXTOKEN 100

enum { NAME, PARENS, BRACKETS };

void dcl(void);
void dirdcl(void);
int gettoken(void);

int tokentype;
char token[MAXTOKEN];
char name[MAXTOKEN];
char datatype[MAXTOKEN];
char out[MAXTOKEN * 10];
char line[MAXTOKEN * 10];
char *pl = line;

/* dcl: convert declaration to word description */
/*
 * TODO:
 * x skip empty lines '\n\0'
 * - capture each input line
 * - cache error messages and number of errors
 * - if there is an error, output error messages and input line
 */
int main(int argc, char **argv)
{
  while (gettoken() != EOF) {
    if (tokentype == '\n') {
      pl = line;
      pl[0] = '\0';
      continue;
    }

    strcpy(datatype, token);
    out[0] = '\0';
    dcl();
    *pl = '\0';

    if (tokentype != '\n') {
      printf("syntax error\n");
    } else {
      //printf("%s: %s %s\n", name, out, datatype);
    }

    printf("HERE\n");
    printf("line: %s", line);

    pl = line;
    pl[0] = '\0';
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

  if (tokentype == '\n')
    return;

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
    *pl++ = c;
    if ((c = getch()) == ')') {
      *pl++ = c;
      strcpy(token, "()");
      return tokentype = PARENS;
    } else {
      ungetch(c);
      return tokentype = '(';
    }
  } else if (c == '[') {
    *pl++ = c;
    for (*pt++ = c; (c = getch()) != ']'; ) {
      *pl++ = c;
      *pt++ = c;
    }
    *pl++ = c;
    *pt++ = c;
    *pt = '\0';
    return tokentype = BRACKETS;
  } else if (isalpha(c)) {
    *pl++ = c;
    for (*pt++ = c; isalnum(c = getch()); ) {
      *pl++ = c;
      *pt++ = c;
    }
    *pt = '\0';
    ungetch(c);
    return tokentype = NAME;
  } else {
    *pl++ = c;
    return tokentype = c;
  }
}

