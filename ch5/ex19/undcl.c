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
char out[MAXTOKEN];
char line[MAXTOKEN * 10];
char *pl = line;

/* undcl: convert word description to declaration */
int main(int argc, char **argv)
{
  int type;
  int prevtype;
  char temp[MAXTOKEN * 2];

  while ((type = gettoken()) != EOF) {
    strcpy(out, token);

    prevtype = type;
    while ((type = gettoken()) != '\n') {
      if (type == PARENS || type == BRACKETS) {
        if (prevtype == '*') {
          sprintf(temp, "(%s)", out);
          strcpy(out, temp);
        }

        strcat(out, token);
      } else if (type == '*') {
        sprintf(temp, "*%s", out);
        strcpy(out, temp);
      } else if (type == NAME) {
        sprintf(temp, "%s %s", token, out);
        strcpy(out, temp);
      } else
        printf("invalid input at %s\n", token);

      prevtype = type;
    }

    *pl = '\0';
    printf("line: %s\n", line);
    printf("code: %s\n", out);
    printf("\n");

    line[0] = '\0';
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
    if (c != '\n')
      *pl++ = c;

    return tokentype = c;
  }
}

