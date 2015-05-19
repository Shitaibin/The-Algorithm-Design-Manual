
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
  int i;                /* counter */

  g->nvertices = 0;
  g->nedges = 0;
  g->directed = directed;

  for (i=0; i<MAXV; ++i)  g->degree[i] = 0;
  for (i=0; i<MAXV; ++i)  g->edges[i] = NULL;
}

void read_graph(graph *g, bool directed)
{
  int i;
  int m;          /* no. of edges */
  int x, y;       /* vertices x and y */

  initialize_graph(g, directed);
  
  printf("input the number of vertices and edges:"); 
  scanf("%d %d", &(g->nvertices), &m);
  for (i=0; i<m; ++i) {
    printf("input two vertices of an edge:");
    scanf("%d %d", &x, &y); 
    insert_graph(g, x, y, 1, directed); // set the weight to 1 for unweighted graph
  }
}

// this function is not exist in Skiena's code
void read_weighted_graph(graph *g, bool directed)
{
  int i;
  int m;          /* no. of edges */
  int x, y;       /* vertices x and y */
  int weight;     /* weight of edge (x, y) */

  initialize_graph(g, directed);
  
  printf("input the number of vertices and edges:"); 
  scanf("%d %d", &(g->nvertices), &m);
  for (i=0; i<m; ++i) {
    printf("input two vertices of an edge:");
    scanf("%d %d %d", &x, &y, &weight); 
    insert_graph(g, x, y, weight, directed);
  }
}

void insert_graph(graph *g, int x, int y, int weight, bool directed)
{
  edgenode *p;    /* temperary pointer */

  p = malloc(sizeof(edgenode));

  p->weight = weight;
  p->y = y;
  p->next = g->edges[x];

  g->edges[x] = p;
  g->degree[x] ++;

  if (directed == FALSE)
    insert_graph(g, y, x, weight, TRUE);
  else
    g->nedges++;
}

void delete_graph(graph *g, int x, int y, bool directed)
{
  int i;                      /*  counter */
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

void print_weighted_graph(graph *g)
{
  int i;
  edgenode *p;

  for (i=1; i<=g->nvertices; ++i) {
    printf("node %d:\n", i);
    p = g->edges[i];
    while (p != NULL) {
      printf("\t (%d, %d):%d\n", i, p->y, p->weight);
      p = p->next;
    }
    printf("\n");
  }
}


void find_path(int start, int end, int parents[])
{
  if ((start == end) || (end == -1)) {
    printf("%d\n", start);
  } else {
    find_path(start, parents[end], parents);
    printf(" %d", end);
  }
}

