/*    prim.c
 *
 *    Compute minimum spanning tree of graphs via Dijkstra/Prim's algorithm
 *
 *    2015-05-11 23:26
 *    Altered by James Shi
 */

#include <stdlib.h>
#include "bool.h"
#include "graph.h"

#define MAXINT    1000007

int parent[MAXV+1];     /* discovery relation */

void print_edge(int v)
{
  printf("new edge (%d, %d)\n", parent[v], v);
}

void prim(graph *g, int start)
{
  int i;
  edgenode *p;
  bool intree[MAXV+1];    /* is the vertex in the tree yet? */
  int distance[MAXV+1];   /* cost of adding to tree */
  int v;                  /* current vertex to process */
  int w;                  /* candidate next vertex */
  int weight;             /* edge weight */
  int dist;               /* best current distance from start */

  for (i=1; i<=g->nvertices; ++i) {
    intree[i] = FALSE;
    parent[i] = -1;
    distance[i] = MAXINT;
  }

  distance[start] = 0;
  v = start;

  while (intree[v] == FALSE) {
    intree[v] = TRUE;

    // print the new edge
    print_edge(v);

    p = g->edges[v];
    while (p != NULL) {
      w = p->y;
      weight = p->weight;
      if ((distance[w] > weight) && (intree[w] == FALSE)) {
        distance[w] = weight;
        parent[w] = v;
      }
      p = p->next;
    }

    v = 1;
    dist = MAXINT;
    for (i=1; i<=g->nvertices; ++i) {
      if (dist > distance[i] && intree[i] == FALSE) {
        dist = distance[i];
        v = i;
      }
    }
  }
}

int main()
{
  graph g;
  int i;
  
  read_weighted_graph(&g, FALSE);
  printf("\n");
  print_weighted_graph(&g);

  printf("Out of Prim:\n");
  prim(&g, 1);

//  for(i=1; i<=g.nvertices; ++i) {
//    find_path(1, i, parent);
//  }
  printf("\n");

  return 0;
}
