#include <stdio.h>
#include "../bool.h"
#include "../queue.h"
#include "../graph.h"

bool processed[MAXV+1];
bool discovered[MAXV+1];
int level[MAXV+1];

void initialize_search(graph *g)
{
  int i;
  for (i=0; i<=g->nvertices; ++i) {
    processed[i] = FALSE;
    discovered[i] = FALSE;
    level[i] = 0;
  }
}

process_vertex_early(int v)
{
}

process_vertex_late(int v)
{
}

process_edge(int x, int y)
{
}

int bfs(graph *g, int v, int w)
{
  queue q;
  edgenode *p;
  int y;
  int sl, n;
  bool first_meet;

  init_queue(&q);
  enqueue(&q, v);
  discovered[v] = TRUE;

  sl = 0;
  first_meet = TRUE;
  while (empty_queue(&q) == FALSE) {
    v = dequeue(&q);

    p = g->edges[v]; 
    while (p != NULL) {
      y = p->y;
      if (discovered[y] == FALSE) {
        level[y] = level[v] + 1;
        if (first_meet == FALSE && level[y] > sl) {
          p = p->next;
          continue;
        } else if (y == w) {
          if (first_meet) {
            sl = level[y];
            n = 1;
            first_meet = FALSE;
          } else {
            if (level[y] < sl) {
              sl = level[y];
              n = 1;
            } else {
              ++n;
            }
          }
        } else {
          //printf("enqueue %d\n", y);
          enqueue(&q, y);
          discovered[y] = TRUE;
        }
      }
      p = p->next;
    }
  }
  return n;
}


int main()
{
  graph g;
  int i, res;
  int u, w;

  read_graph(&g, TRUE);
  printf("input vertex u and vertex w: ");
  scanf("%d %d", &u, &w);

  print_graph(&g);
  initialize_search(&g);
  res = bfs(&g, u, w);
  printf("there are %d path(s) from %d to %d\n", res, u, w);
  return 0;
}
