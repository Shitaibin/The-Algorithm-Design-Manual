/*    dijkstra.c
 *
 *    Compute shortest paths in weighted graphs using Dijstra's algorithm
 *
 *    by: Steven Skiena
 *
 *    2015-05-18 19:25
 *    Altered by James Shi
 */


#include <stdio.h>
#include <stdlib.h>
#include "graph.h"
#include "bool.h"
#include "stack.h"

#define MAXINT    1000007
int parent[MAXV+1];         /*  discovery relation */
stack s;


void dijkstra(graph *g, int start)
{
  int i;          /* counter */
  edgenode *p;    /* temporary pointer */
  bool intree[MAXV+1];    /* is the vertex in the tree yet? */
  int distance[MAXV+1];   /* distance vertex is from start */
  int v;                  /* current vertex to precess */
  int w;                  /* candidate next vertex */
  int weight;             /* edge weight */
  int dist;               /* best current distance from start */

  for (i=1; i<=g->nvertices; ++i) {
    intree[i] = FALSE;
    distance[i] = MAXINT;
    parent[i] = -1;
  }

  distance[start] = 0;
  v = start;

  while (intree[v] == FALSE) {
    intree[v] = TRUE;
    p = g->edges[v];
    while (p != NULL) {
      w = p->y;
      weight = p->weight;
      if (distance[w] > (distance[v]+weight)) {
        distance[w] = distance[v]+weight;
        parent[w] = v;
      }
      p = p->next;
    }

    v = 1;
    dist = MAXINT;
    for (i=1; i<=g->nvertices; ++i) {
      if ((intree[i] == FALSE) && (dist >= distance[i])) {
        dist = distance[i];
        v = i;
      }
    }
	  /* for test: print distance table */
	  printf("\ndistance table\n");
	  for (i=1; i<=g->nvertices; ++i)
	    printf("%d\t%d\n", i, distance[i]);
	  }
}

void print_parent(graph *g)
{
  int i;

  printf("parent[]:\n");
  for (i=1; i<=(g->nvertices); ++i)
    printf("%d %d\n", i, parent[i]);
  printf("\n");
}

int main()
{
  graph g;
  int i;
  int start;        /* start vertex */

  read_weighted_graph(&g, FALSE);
  print_weighted_graph(&g);
  start = 6;        /* the same as text book */
  dijkstra(&g, start);

  print_parent(&g); 
  
  printf("\npath from vertex %d:\n", start);
  for (i=1; i<=(g.nvertices); ++i)
    find_path(start, i, parent);

  return 0;
}
