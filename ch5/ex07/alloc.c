#define ALLOCSIZE 500 * 1000

static char allocbuf[ALLOCSIZE];
static char *ap = allocbuf;

char *alloc(int n)
{
  if (ap + n <= allocbuf + ALLOCSIZE) {
    ap += n;
    return ap - n;
  } else
    return 0;
}

