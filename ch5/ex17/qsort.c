#include <string.h>

void substr(char *s, char *t, int field, char delim);

void myqsort(void *v[], int left, int right, int (*comp)(void *, void *),
             int field, char delim)
{
  int i, last;
  char s[100], t[100];
  void swap(void *v[], int, int);

  if (left >= right)
    return;

  swap(v, left, (left + right)/2);

  last = left;

  // Michael|Singhurse|M
  // Ursula|Singhurse|F
  for (i = left+1; i <= right; i++) {
    // set s and t from 
    // s = v[i];
    // t = v[left];
    substr(s, v[i], field, delim);
    substr(t, v[left], field, delim);

    if ((*comp)(s, t) < 0)
      swap(v, ++last, i);
  }

  swap(v, left, last);
  myqsort(v, left, last-1, comp, field, delim);
  myqsort(v, last+1, right, comp, field, delim);
}

void substr(char *s, char *t, int field, char delim)
{
  // *t = Michael|Singhurse|M
  // *t = Ursula|Singhurse|F
  // field = 1
  // delim = |
  if (field == 0) {
    strcpy(s, t);
    return;
  }

  int si, ti;

  si = 0;
  for (ti = 0; t[ti] != '\0'; ti++)
    if (field == 1 && t[ti] != delim)
      s[si++] = t[ti];
    else if (field == 1 && t[ti] == delim) {
      s[si] = '\0';
      return;
    } else if (field > 1 && t[ti] == delim)
      field--;

  s[si] = '\0';
}

void swap(void *v[], int i, int j)
{
  void *temp;

  temp = v[i];
  v[i] = v[j];
  v[j] = temp;
}
