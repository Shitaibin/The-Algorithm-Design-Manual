/*    topsort1.c
 *    Topologically sort a directed acyclic graph by DFS numbering (DAG)
 *
 *    by: Steven Skinea
 *
 *    2015-05-06 12:49
 *    Altered by James Shi
 */


#include <stdio.h>
#include "bool.h"
#include "graph.h"
#include "stack.h"

stack sorted;

extern bool processed[];        /* which vertices have been processed */
extern bool discovered[];       /* which vertices have been found */
extern int parent[];            /* discovery relation */

extern int entry_time[];        /* time of vertex entry */
extern int exit_time[];         /* time of vertex exit */

void process_vertex_early(int v)
{
}

void process_vertex_late(int v)
{
  push(&sorted, v);
}

void process_edge(int x, int y)
{
  int class;  /* edge class */

  class = edge_classification(x, y);
  if (class == BACK)
    printf("Warning: directed cycle found, not a DAG\n");
}

void topsort(graph *g)
{
  int i;

  for (i=1; i<=(g->nvertices); ++i)
    if (discovered[i] == FALSE)
      dfs(g, i);

  printf("topsort: ");
  print_stack(&sorted);
}


int main()
{
  graph g;

  initialize_search(&g);
  init_stack(&sorted);
  read_graph(&g, TRUE);
  print_graph(&g);
  topsort(&g);
  return 0;
}
