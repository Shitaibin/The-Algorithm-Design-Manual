/*    floyd.c
 *
 *    Compute all-pairs shortest paths in weighted graphs.
 *
 *    by: Steven Skiena
 *
 *    2015-05-19 13:07
 *    Altered by James Shi
 */

#include <stdio.h>
#include <stdlib.h>
#include "bool.h"

#define MAXV          100             /* maximum number of vertices */
#define MAXDEGREE     50              /* maximum number of a vertex */

#define MAXINT        100007

typedef struct{
  int v;                              /* neighboring vertex */
  int weight;                         /* edge weight */
  bool in;                            /* is the edge "in" the solution ? */
} edge;

/* never used */
typedef struct {
  edge edges[MAXV+1][MAXV+1];         /* adjacency info */
  int degree[MAXV+1];                 /* out degree of each vertex */
  int nvertices;                      /* number of vertices in the graph */
  int nedges;                         /* number of edges in the graph */
} graph;

typedef struct {
  int weight[MAXV+1][MAXV+1];         /* adjacency/weight info */
  int nvertices;
} adjacency_matrix;

void initialize_adjacency_matrix(adjacency_matrix *g)
{
  int i, j;                           /* counter */

  g->nvertices = 0;
  for (i=1; i <= MAXV; ++i)
    for (j=1; j <= MAXV; ++j)
      g->weight[i][j] = MAXINT;
}

void read_adjacency_matrix(adjacency_matrix *g, bool directed)
{
  int i;
  int m;
  int x, y, w;

  initialize_adjacency_matrix(g);

  scanf("%d %d", &(g->nvertices), &m);
  for (i=0; i<m; ++i) {
    scanf("%d%d%d", &x, &y, &w);
    g->weight[x][y] = w;
    if (directed == FALSE)
      g->weight[y][x] = w;
  }
}

void print_graph(adjacency_matrix *g)
{
  int i, j;                           /* counters */

  for (i=1; i<=(g->nvertices); ++i) {
    printf("%3d:", i);
    for (j=1; j<=(g->nvertices); ++j)
      if (g->weight[i][j] < MAXINT) printf(" %3d", j);
    printf("\n");
  }
}

void print_adjacency_matrix(adjacency_matrix *g)
{
  int i, j;                           /* counters */

  for (i=1; i<=(g->nvertices); ++i) {
    printf("%3d:", i);
    for (j=1; j<=(g->nvertices); ++j)
      printf(" %3d", g->weight[i][j]);
    printf("\n");
  }
}


void floyd(adjacency_matrix *g)
{
  int i, j;
  int k;
  int through_k;

  for (k=1; k<=(g->nvertices); ++k)
    for (i=1; i<=(g->nvertices); ++i)
      for (j=1; j<=(g->nvertices); ++j) {
        through_k = g->weight[i][k] + g->weight[k][j];
        if (through_k < g->weight[i][j]) g->weight[i][j] = through_k;
      }
}

int main()
{
  bool directed = TRUE;  /* FALSE for floyd.in01, TRUE for floyd.in02 */
  adjacency_matrix g;

  scanf("%d", &directed);
  read_adjacency_matrix(&g, directed);     /* or you can build a adjacency matrix based on graph */
  printf("graph is:\n");
  print_graph(&g);

  floyd(&g);

  printf("all-pairs shorest path by floyd:\n");
  print_adjacency_matrix(&g);

  if (directed == FALSE)
    printf("you must find the path form i to i is not 0,\nthe value is the smallest weight of its edges\nmultiply by 2.\n");
  else
    printf("what's the meaning of i to i? the shorest directed cycle, right?\n");
  return 0;
}
