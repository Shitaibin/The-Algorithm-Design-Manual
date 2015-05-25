/*    kruskal.c
 *
 *    Compute minimum spanning trees of graphs via Kruskal's algorithm
 *
 *    by: Steven Skiena
 *
 *    2015-05-12 00:30
 *    Altered by James Shi
 */

#include <stdlib.h>
#include <stdio.h>
#include "graph.h"
#include "bool.h"
#include "set_union.h"

#define MAXINT    1000007

typedef struct {
  int x, y;     /* vertex x and y */
  int weight;   /* weight of edge {v, y} */
} edge_pair;

void to_edge_array(graph *g, edge_pair e[])
{
  int i, m;       /* counter */
  edgenode *p;

  m = 1;
  for (i=1; i<=g->nvertices; ++i) {
    p = g->edges[i];
    while (p != NULL) {
      if (p->y > i) {
        e[m].x = i;
        e[m].y = p->y;
        e[m].weight = p->weight;
        ++m;
      }
      p = p->next;
    }
  }
}

bool weight_compare(edge_pair *x, edge_pair *y)
{
  return ( x->weight > y->weight);
}

void kruskal(graph *g)
{
  int i;                      /* counter */
  set_union s;                /* union and find set */
  edge_pair e[MAXV+1];        /* pair of edge */
  bool weight_compare();      /* compare method for qsort */

  set_union_init(&s, g->nvertices);

  printf("initialize set union\n");

  to_edge_array(g, e);
  qsort(&e, g->nedges, sizeof(edge_pair), weight_compare);

  for(i=0; i<(g->nedges); ++i) {
    print_set_union(&s);
    if (!same_component(&s, e[i].x, e[i].y)) {
      printf("edge (%d,%d) of weight %d in MST\n", e[i].x, e[i].y, e[i].weight);
      union_sets(&s, e[i].x, e[i].y);
    }
  }
 
  // final set union
  printf("the final set union:\n");
  print_set_union(&s);
}

int main()
{
  graph g;
  read_weighted_graph(&g, FALSE);
  printf("\n");
  print_weighted_graph(&g);
  
  printf("Out of Kruskal\n");
  kruskal(&g);

  return 0;
}
