/*    set_union.c
 *
 *    Implementation of a heap / priority queue abstract data type
 *
 *    by: Steven Skiena
 *
 *    2015-05-12 00:20
 *    Altered by James Shi
 */

#include "set_union.h"
#include "bool.h"

void set_union_init(set_union *s, int n)
{
  int i;

  for (i=1; i<=n; ++i) {
    s->p[i] = i;
    s->size[i] = 1;
  }
  s->n = n;
}

int find(set_union *s, int x)
{
  if (s->p[x] == x)
    return x;
  else 
    return ( find(s, s->p[x]) );
}

int union_sets(set_union *s, int s1, int s2)
{
  int r1, r2;   /* root of s1 and s2 */

  r1 = find(s, s1);
  r2 = find(s, s2);

  printf("s1=%d r1=%d s2=%d r2=%d\n", s1, r1, s2, r2);

  if (r1 == r2) return 0;
  if (s->size[r1] >= s->size[r2]) {
    s->p[r2] = r1;
    s->size[r1] += s->size[r2];
  } else {
    s->p[r1] = r2;
    s->size[r2] += s->size[r1];
  }
  return 0;
}

bool same_component(set_union *s, int s1, int s2)
{
  return ( find(s, s1) == find(s, s2) );
}

void print_set_union(set_union *s)
{
  int i;

  for (i=1; i<=s->n; ++i)
    //printf("%d set=%d size=%d\n", i, find(s, i), s->size[i]); // different with Skiena's code
    printf("%d set=%d size=%d\n", i, s->p[i], s->size[i]); // different with Skiena's code

  printf("\n");
}

// path compression
int find_v2(set_union *s, int x)
{
  if (s->p[x] != x)
    s->p[x] = find_v2(s, s->p[x]);

  return s->p[x];
}

int union_sets_v2(set_union *s, int s1, int s2)
{
  int r1, r2;   /* root of s1 and s2 */

  r1 = find_v2(s, s1);
  r2 = find_v2(s, s2);

  printf("s1=%d r1=%d s2=%d r2=%d\n", s1, r1, s2, r2);

  if (r1 == r2) return 0;
  if (s->size[r1] >= s->size[r2]) {
    s->p[r2] = r1;
    s->size[r1] += s->size[r2];
  } else {
    s->p[r1] = r2;
    s->size[r2] += s->size[r1];
  }
  return 0;
}

bool same_component_v2(set_union *s, int s1, int s2)
{
  return ( find_v2(s, s1) == find_v2(s, s2) );
}
