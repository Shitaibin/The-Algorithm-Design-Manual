#include <stdio.h>
#include "bool.h"
#include "graph.h"

extern bool processed[];
extern bool discovered[];
extern int parent[];

process_vertex_early(int v)
{
}

process_vertex_late(int v)
{
  printf("processed vertex %d\n", v);
}

process_edge(int x, int y)
{
  printf("processed edge (%d,%d)\n", x, y);
}

int main()
{
  graph g;
  int i;

  read_graph(&g, FALSE);
  print_graph(&g);
  initialize_search(&g);
  dfs(&g, 1);

  printf("nodes parents:\n");
  for (i=1; i<=g.nvertices; ++i)
    printf("%d: %d\n", i, parent[i]);
  printf("\n");


  return 0;
}
