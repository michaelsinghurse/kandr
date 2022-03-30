#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXWORD 50
#define MAXWORDS 1000

struct tnode {
  char *word;
  int count;
  struct tnode *left;
  struct tnode *right;
};

int isnoise(char *);
struct tnode *addtree(struct tnode *, char *);
struct tnode list[MAXWORDS];
struct tnode *plist;
void tree2list(struct tnode *);
void printlist(struct tnode *, int);
int getword(char *, int);
void qsort(void *, int, int, int (*comp)(void *, void *));
int tnodecmp(struct tnode *, struct tnode *);

int main(int argc, char **argv)
{
  int c, count;
  struct tnode *root;
  char word[MAXWORD];

  root = NULL;
  while ((c = getword(word, MAXWORD)) != EOF)
    if (isalpha(word[0]) && !isnoise(word))
      root = addtree(root, word);

  plist = list;
  tree2list(root);

  count = plist - list;

  qsort(list, 0, count-1, (int (*)(void *, void *)) tnodecmp);
  printlist(list, count);

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
  } else if ((cond = strcmp(w, p->word)) == 0) {
    p->count++;
  } else if (cond < 0)
    p->left = addtree(p->left, w);
  else
    p->right = addtree(p->right, w);

  return p;
}

void tree2list(struct tnode *ptree)
{
  if (ptree == NULL)
    return;

  tree2list(ptree->left);

  *plist++ = *ptree;

  tree2list(ptree->right);
}

void printlist(struct tnode *list, int n)
{
  int i;

  for (i = 0; i < n; i++) {
    printf("%4d %s\n", list[i].count, list[i].word);
  }
}

int isnoise(char *s) {
  return strcmp(s, "the") == 0 ||
    strcmp(s, "a") == 0 ||
    strcmp(s, "and") == 0 ||
    strcmp(s, "is") == 0 ||
    strcmp(s, "an") == 0;
}

int tnodecmp(struct tnode *a, struct tnode *b)
{
  return a->count - b->count;
}
