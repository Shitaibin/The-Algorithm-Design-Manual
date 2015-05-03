#include <stdio.h>
#include "bool.h"
#include "graph.h"

extern bool processed[];
extern bool discovered[];
extern int parent[];


process_vertex_early(int v)
{
  printf("processed vertex %d\n", v);
}

process_vertex_late(int v)
{
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
  bfs(&g, 1);
  printf("nodes parents:\n");
  for (i=1; i<=g.nvertices; ++i) 
    printf("%d: %d\n", i, parent[i]);
  printf("\n");

  printf("path from root to every node\n");
  for (i=0; i<=g.nvertices; ++i)
    find_path(1, i, parent);
  printf("\n");

  return 0;
}
