/*
 * - modify getword so that it does not ignore #values. alternatively just use
 *   getch
 *
 * X define nlist structure
 *
 * X define hastab array
 *
 * - read each line of the file
 *   - if the line begins with #define
 *     - read the next word and store it, read the word (value?) and store it
 *     - call install with name and definition
 *
 * X print all the values stored in the table
 *   - iterate from 0 to HASHSIZE - 1
 *     - walk along the linked list and print name: defn
 *
 */
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct nlist {
  struct nlist *next;
  char *name;
  char *defn;
};

#define MAXWORD 50
#define HASHSIZE 101

static struct nlist *hashtab[HASHSIZE];

int getch(void);
int getword(char *, int);
struct nlist *install(char *, char *);
void printtab(struct nlist **, int);

int main(int argc, char **argv)
{
  char c, word[MAXWORD], name[MAXWORD], defn[MAXWORD];
  int isnewline;

  isnewline = 1;
  while ((c = getchar()) != EOF) {
    if (c == ' ' || c == '\t')
      continue;

    if (isnewline && c == '#') {
      getword(word, MAXWORD);

      if (strcmp(word, "define") == 0) {
        getword(name, MAXWORD);
        getword(defn, MAXWORD);

        printf("found name: %s, defn: %s\n", name, defn); // TODO remove
        install(name, defn);
      }
    }

    if (c == '\n')
      isnewline = 1;
    else
      isnewline = 0;
  }

  printtab(hashtab, HASHSIZE);

  return 0;
}

unsigned hash(char *s)
{
  unsigned hashval;

  for (hashval = 0; *s != '\0'; s++)
    hashval = *s + 31 * hashval;

  return hashval % HASHSIZE;
}

struct nlist *lookup(char *s)
{
  struct nlist *np;

  for (np = hashtab[hash(s)]; np != NULL; np = np->next)
    if (strcmp(s, np->name) == 0)
      return np;

  return NULL;
}

struct nlist *install(char *name, char *defn)
{
  struct nlist *np;
  unsigned hashval;

  if ((np = lookup(name)) == NULL) {
    np = (struct nlist *) malloc(sizeof(*np));

    if (np == NULL || (np->name = strdup(name)) == NULL)
      return NULL;

    hashval = hash(name);
    np->next = hashtab[hashval];
    hashtab[hashval] = np;
  } else
    free((void *) np->defn);

  if ((np->defn = strdup(defn)) == NULL)
    return NULL;

  return np;
}

void printtab(struct nlist **tab, int tabsize)
{
  int i;
  struct nlist *np;

  for (i = 0; i < tabsize; i++)
    for (np = tab[i]; np != NULL; np = np->next)
      printf("%s: %s\n", np->name, np->defn);
}

