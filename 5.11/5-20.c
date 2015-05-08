#include <stdio.h>
#include "../bool.h"
#include "../stack.h"
#include "../graph.h"

bool discovered[MAXV+1]; 
bool processed[MAXV+1];

graph g, f;
int k;

void initialize_search()
{
  int i;

  for (i=0; i<=MAXV; ++i) {
    discovered[i] = FALSE;
    processed[i] = FALSE;
  }
}

void process_edge(int v, int y) {
  // satisfied edge and vertices
  if (g.degree[v] >= k && g.degree[y] >= k) {
    //printf("insert (%d,%d)\n", v, y);
    insert_graph(&f, v, y, FALSE);
  }
}

// simplified dfs
void dfs(graph *g, int v)
{
  edgenode *p;
  int y;

  discovered[v] = TRUE;
  p = g->edges[v];
  while (p!=NULL) {
    y = p->y;
    if (discovered[y] == FALSE) {
      dfs(g, y);
    } else if (processed[y] == FALSE) {
      process_edge(v, y); // only visit a edge once
    }
    p = p->next;
  }
  processed[v] = TRUE;
}

void max_induced_graph(graph *g)
{
  int i;

  for (i=1; i<=g->nvertices; ++i)
    dfs(g, i);
}

// 为了让f使用g中的编号
// nodes whose degree is not zero belong to
// graph f
void set_graph(graph *g, graph *f)
{
  f->nvertices = g->nvertices;
}

int main()
{
  initialize_graph(&g);
  initialize_graph(&f);

  printf("input k: ");
  scanf("%d", &k);
  read_graph(&g, FALSE);
  set_graph(&g, &f);
  
  printf("\ngraph g is\n");
  print_graph(&g);


  initialize_search(&g);
  max_induced_graph(&g);
  printf("k = %d\n", k);
  
  printf("\ngraph f is\n");
  print_graph(&f);

  return 0;
}
