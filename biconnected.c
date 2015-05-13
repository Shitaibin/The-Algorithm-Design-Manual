/*    biconnected.c
 *    Identify articulation vertices in a graph
 *
 *    by: Steven Skinea
 *
 *    2015-05-04 17:56
 *    Altered by James Shi
 */





#include "bool.h"
#include "graph.h"
#include "queue.h"
#include <stdio.h>

extern bool processed[];
extern bool discovered[];
extern int parent[];

extern int entry_time[MAXV+1];
extern int exit_time[MAXV+1];

int reachable_ancestor[MAXV+1];
int tree_out_degree[MAXV+1];

void process_vertex_early(int v)
{
  /* make reachable ancestor be himself when first visit */
  reachable_ancestor[v]= v; 
  printf("reachable_ancestor[%d]=%d\n", v, reachable_ancestor[v]);
}

void process_vertex_late(int v)
{
  bool root;
  int time_v;       /* entry time of current vertex v */
  int time_parent;  /* entry time of parent vertex */

  if (parent[v] < 1) {    /* test if v is the root */
    if (tree_out_degree[v] > 1)
      printf("root articulation vertex: %d\n", v);
    return ;
  }

  root = (parent[parent[v]] < 1);   /* test if parent[v] is root */
  if ((reachable_ancestor[v] == parent[v]) && (!root))
    printf("parent articulation vertex: %d\n", parent[v]);

  if (reachable_ancestor[v] == v) {
    printf("bridge articulation vertex: %d\n", parent[v]);
    if (tree_out_degree[v] > 0)   /* test if v is a leaf */
      printf("bridge articulation vertex: %d\n", v);
  }
  
  //printf("reachable_ancestor[%d]=%d\n", v, reachable_ancestor[v]);

  time_v = entry_time[reachable_ancestor[v]];
  time_parent = entry_time[reachable_ancestor[parent[v]]];

  if (time_v < time_parent) {
    reachable_ancestor[parent[v]] = reachable_ancestor[v];
    printf("reachable_ancestor[parent[%d]]=%d\n", v, reachable_ancestor[parent[v]]);
  }
}

void process_edge(int x, int y)
{
  int class;    /* edge class */

  class = edge_classification(x,y);
  /*printf("(%d,%d) class %d tree_out_degree[%d]=%d\n", x, y, class, x, tree_out_degree[x]);*/
  if (class == TREE)
    tree_out_degree[x] = tree_out_degree[x] + 1;

  /* y is an ancestor of x */
  if ((class == BACK) && (parent[x] != y)) {
    if (entry_time[y] < entry_time[reachable_ancestor[x]]) {
      reachable_ancestor[x] = y;
      printf("reachable_ancestor[%d]=%d\n", x, y);
    }
  }
}

void articulation_vertices(graph *g)
{
  int i;

  for (i=1; i<=(g->nvertices); ++i)
    tree_out_degree[i] = 0;

  initialize_search(&g);

  for (i=1; i<=(g->nvertices); ++i)
    if (discovered[i] == FALSE)
      dfs(g, i);
}

int main()
{
  graph g;
  int i;

  read_graph(&g, FALSE);
  print_graph(&g);

  articulation_vertices(&g);

  return 0;
}
