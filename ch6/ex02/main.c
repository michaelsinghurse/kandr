#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXWORD 50

struct tnode {
  char *word;
  int count;
  struct tnode *left;
  struct tnode *right;
};

struct tnode *addtree(struct tnode *, char *);
void treeprint(struct tnode *);
int getword(char *, int);
int istype(char *);
int isvarname(char *);
char *slice(char *, char *, int, int);

int main(int argc, char **argv)
{
  int c, isdeclaration, isnewline, nchars;
  struct tnode *root;
  char word[MAXWORD], substring[MAXWORD];

  nchars = 6;
  if (argc > 1 && isdigit(*argv[1]))
    nchars = atoi(argv[1]);

  root = NULL;
  isnewline = 1;
  isdeclaration = 0;
  while ((c = getword(word, MAXWORD)) != EOF) {
    if (isnewline && istype(word)) {
      isdeclaration = 1;
    } else if (isdeclaration && isvarname(word)) {
      if (strlen(word) < nchars)
        strcpy(substring, word);
      else
        slice(substring, word, 0, nchars);
      
      root = addtree(root, substring);
    }

    if (c == '\n') {
      isnewline = 1; 
      isdeclaration = 0;
    } else
      isnewline = 0;
  }

  treeprint(root);

  return 0;
}

struct tnode *talloc(void)
{
  return (struct tnode *) malloc(sizeof(struct tnode));
}

struct tnode *addtree(struct tnode *p, char *w)
{
  int cond;

  if (p == NULL) {
    p = talloc();
    p->word = strdup(w);
    p->count = 1;
    p->left = p->right = NULL;
  } else if ((cond = strcmp(w, p->word)) == 0)
    p->count++;
  else if (cond < 0)
    p->left = addtree(p->left, w);
  else
    p->right = addtree(p->right, w);

  return p;
}

void treeprint(struct tnode *ptree)
{
  if (ptree == NULL)
    return;

  treeprint(ptree->left);
  printf("%4d %s\n", ptree->count, ptree->word);
  treeprint(ptree->right);
}

int istype(char *w)
{
  return strcmp(w, "int") == 0 ||
    strcmp(w, "char") == 0 ||
    strcmp(w, "void") == 0 ||
    strcmp(w, "float") == 0 ||
    strcmp(w, "double") == 0;
}

int isvarname(char *w)
{
  return isalpha(*w) || *w == '_';
}

char *slice(char *s, char *t, int i, int n)
{
  char *ps;

  ps = s;
  while (n-- > 0) {
    *ps++ = t[i++];
  }

  *ps = '\0';

  return s;
}

