#include <stdio.h>
#include "../bool.h"
#include "../stack.h"
#include "../graph.h"

extern bool processed[];
extern bool discovered[];
extern int parent[];


extern int entry_time[];
extern int exit_time[];

bool is_triangle;
bool finish;

void process_vertex_early(int v)
{
}

void process_vertex_late(int v)
{
}

void process_edge(int v, int y)
{
  int class;

  class = edge_classification(v, y);
  if (class == BACK && parent[parent[v]] == y) {
    printf("there is a triangle: %d %d %d\n", y, parent[v], v);
    finish = TRUE;
    is_triangle = TRUE;
    return;
  }
}

void find_triangle(graph *g)
{
  int i;

  for (i=0; i<g->nvertices; ++i)
    dfs(g, i);

  if (is_triangle == FALSE)
    printf("there is no triangle\n");
}

int main()
{
  graph g;
  
  is_triangle = FALSE;
  finish = FALSE;

  initialize_graph(&g);
  read_graph(&g, FALSE);
  print_graph(&g);

  initialize_search(&g);
  find_triangle(&g);

  return 0;
}
