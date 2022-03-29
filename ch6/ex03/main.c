#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXWORD 50
#define MAXLINES 1000

struct tnode {
  char *word;
  int lines[MAXLINES];
  int *plines;
  struct tnode *left;
  struct tnode *right;
};

int includes(int, int *, int);
int isnoise(char *);
struct tnode *addtree(struct tnode *, char *, int);
void treeprint(struct tnode *);
int getword(char *, int);

int main(int argc, char **argv)
{
  int c, lineno;
  struct tnode *root;
  char word[MAXWORD];

  root = NULL;
  lineno = 1;
  while ((c = getword(word, MAXWORD)) != EOF) {
    if (c == '\n')
      lineno++;

    if (isalpha(word[0]) && !isnoise(word))
      root = addtree(root, word, lineno);
  }

  treeprint(root);

  return 0;
}

struct tnode *talloc(void)
{
  return (struct tnode *) malloc(sizeof(struct tnode));
}

struct tnode *addtree(struct tnode *p, char *w, int lineno)
{
  int cond;

  if (p == NULL) {
    p = talloc();
    p->word = strdup(w);
    *p->lines = lineno;
    p->plines = p->lines + 1;
    p->left = p->right = NULL;
  } else if ((cond = strcmp(w, p->word)) == 0) {
    if (!includes(lineno, p->lines, p->plines - p->lines)) { 
      *p->plines = lineno;
      p->plines++;
    }
  } else if (cond < 0)
    p->left = addtree(p->left, w, lineno);
  else
    p->right = addtree(p->right, w, lineno);

  return p;
}

void treeprint(struct tnode *ptree)
{
  if (ptree == NULL)
    return;

  treeprint(ptree->left);

  printf("%15s ", ptree->word);
  int *pl = ptree->lines;
  while (pl < ptree->plines - 1) {
    printf("%d, ", *pl);
    pl++;
  }
  printf("%d\n", *pl);

  treeprint(ptree->right);
}

int isnoise(char *s) {
  return strcmp(s, "the") == 0 ||
    strcmp(s, "a") == 0 ||
    strcmp(s, "and") == 0 ||
    strcmp(s, "is") == 0 ||
    strcmp(s, "an") == 0;
}

int includes(int needle, int *haystack, int n)
{
  for (int i = 0; i < n; i++)
    if (needle == haystack[i])
      return 1;

  return 0;
}

