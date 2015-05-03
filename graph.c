
/*    graph.c
 *    Ageneric adjacency list graph data type.
 *
 *    by: Steven Skiena
 *
 *    2015-05-02 19:26
 *    Altered by James Shi
 */


#include "bool.h"
#include "queue.h"
#include "graph.h"

void initialize_graph(graph *g, bool directed)
{
  int i;

  g->nvertices = 0;
  g->nedges = 0;
  g->directed = directed;

  for (i=0; i<MAXV; ++i)  g->degree[i] = 0;
  for (i=0; i<MAXV; ++i)  g->edges[i] = NULL;
}

void read_graph(graph *g, bool directed)
{
  int i;
  int m;
  int x, y;

  initialize_graph(g, directed);
  
  printf("input the number of vertices and edges:");
  scanf("%d %d", &(g->nvertices), &m);
  for (i=0; i<m; ++i) {
    printf("input two vertices of an edge:");
    scanf("%d %d", &x, &y);
    insert_graph(g, x, y, directed);
  }
}

void insert_graph(graph *g, int x, int y, bool directed)
{
  edgenode *p;

  p = malloc(sizeof(edgenode));

  p->weight = NULL;
  p->y = y;
  p->next = g->edges[x];

  g->edges[x] = p;
  g->degree[x] ++;

  if (directed == FALSE)
    insert_graph(g, y, x, TRUE);
  else
    g->nedges++;
}

void delete_graph(graph *g, int x, int y, bool directed)
{
  int i;
  edgenode *p, *p_back;       /* temporary pointers */

  p = g->edges[x];
  p_back = NULL;

  while (p != NULL) {
    if (p->y == y) {
      g->degree[x] --;
      if (p_back != NULL)
        p_back->next = p->next;
      else
        g->edges[x] = p->next;

      free (p);

      if (directed == FALSE)
        delete_graph(g, y, x, TRUE);
      else
        g->nedges --;
      return ;
    } else {
      p = p->next;
    }
  }
  printf("Warning: deletion(%d,%d) not found in g.\n", x, y);
}

void print_graph(graph *g)
{
  int i;
  edgenode *p;

  for (i=1; i<=g->nvertices; ++i) {
    printf("%d: ", i);
    p = g->edges[i];
    while (p != NULL) {
      printf(" %d", p->y);
      p = p->next;
    }
    printf("\n");
  }
}

