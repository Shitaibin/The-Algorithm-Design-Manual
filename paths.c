/*    path.c
 *
 *    Enumerate the paths in a graph via backtracking
 *
 *    by:Steven Skiena
 *
 *    2015-06-01 23:40
 *    Altered by James Shi
 */

#include "bool.h"
#include "backtrack.h"
#include "graph.h"
#include <stdio.h>

int solution_count;           /* how many solutions are there? */
graph g;                      /* graph to traverse */

void process_solution(int a[], int k)
{
  int i;

  ++solution_count;
  printf("{");
  for (i=1; i<=k; ++i)
    printf(" %d", a[i]);
  printf(" }\n");
}

bool is_a_solution(int a[], int k, int t)
{
  return (a[k] == t);
}

void make_move(int a[], int k, int n)
{
}

void unmake_move(int a[], int k, int n)
{
}

void construct_candidates(int a[], int k, int n, int c[], int *ncandidates)
{
  int i;
  bool in_sol[NMAX];          /* what's already in the solution? */
  edgenode *p;                /* temp pointer */
  int last;

  for (i=1; i<NMAX; ++i)  in_sol[i] = FALSE;
  for (i=1; i<k; ++i) in_sol[a[i]] = TRUE;

  if (k == 1) {
    c[0] = 1;
    *ncandidates = 1;
  } else {
    *ncandidates = 0;
    last = a[k-1];
    p = g.edges[last];
    while (p != NULL) {
      if (!in_sol[p->y]) {
        c[(*ncandidates)++] = p->y;
      }
      p = p->next;
    }
  }
}

int main()
{
  int a[NMAX];
  int i;
  read_graph(&g, FALSE);
  print_graph(&g);

  for (i=1; i<=g.nvertices; ++i) {
    printf("\nPaths from 1 to %d: ", i);
    backtrack(a, 0, i);
  }

  return 0;
}

