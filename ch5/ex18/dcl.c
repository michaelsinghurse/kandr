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
char errs[MAXTOKEN * 10];
int errcount = 0;
int openparens = 0;
int openbrackets = 0;

/* dcl: convert declaration to word description */
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

    if (tokentype != '\n' || errcount > 0 || openparens > 0 || openbrackets > 0) {
      if (openparens > 0)
        printf("syntax error in declaration: %s\n\tmissing closing )\n", line);
      else if (openbrackets > 0) 
        printf("syntax error in declaration: %s\n\tmissing bracket ]\n", line);
      else
        printf("syntax error in declaration: %s\n%s", line, errs);
    } else
      printf("%s: %s %s\n", name, out, datatype);

    pl = line;
    pl[0] = '\0';
    name[0] = '\0';
    datatype[0] = '\0';
    errs[0] = '\0';
    errcount = 0;
    openparens = 0;
    openbrackets = 0;
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
      errcount += 1;
      strcat(errs, "\terror: missing closing )\n");
  } else if (tokentype == NAME)
    strcpy(name, token);
  else {
    errcount += 1;
    strcat(errs, "\terror: expected name or (dcl)\n");
  }

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
    openparens++;    
    if ((c = getch()) == ')') {
      *pl++ = c;
      openparens--;
      strcpy(token, "()");
      return tokentype = PARENS;
    } else {
      ungetch(c);
      return tokentype = '(';
    }
  } else if (c == '[') {
    *pl++ = c;
    openbrackets++;
    for (*pt++ = c; (c = getch()) != ']'; ) {
      *pl++ = c;
      *pt++ = c;
    }
    *pl++ = c;
    *pt++ = c;
    openbrackets--;
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

    if (c == ')')
      openparens--;

    return tokentype = c;
  }
}

