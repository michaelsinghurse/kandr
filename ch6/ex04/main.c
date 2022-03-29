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
void printwords(struct tnode *);
int getword(char *, int);
void tree2list(struct tnode *, struct tnode *);
void qsort(void *, int, int, int (*comp)(void *, void *));
int structcmp(void *, void *);

int main(int argc, char **argv)
{
  int c, count;
  struct tnode *root;
  char word[MAXWORD];
  struct tnode words[MAXWORDS];

  root = NULL;
  while ((c = getword(word, MAXWORD)) != EOF)
    if (isalpha(word[0]) && !isnoise(word))
      root = addtree(root, word);

  count = tree2list(root, words);
  //qsort(words);
  printwords(words, count);

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

int tree2list(struct tnode *ptree, struct tnode *list)
{
  int count = 0;

  if (ptree == NULL)
    return count;

  count += treeprint(ptree->left);
  printf("%5d %s\n", ptree->count, ptree->word);
  count += 1;
  count += treeprint(ptree->right);

  return count;
}

int isnoise(char *s) {
  return strcmp(s, "the") == 0 ||
    strcmp(s, "a") == 0 ||
    strcmp(s, "and") == 0 ||
    strcmp(s, "is") == 0 ||
    strcmp(s, "an") == 0;
}

