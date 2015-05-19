/*    bfs-dfs.c
 *    A generic implementation of graph traversal: breadth-first
 *    and depth-first search
 *
 *    by: Steven Skina
 *
 *    2015-05-02 19:48
 *    Altered by James Shi
 */





#include "bool.h"
#include "graph.h"
#include "queue.h"

bool processed[MAXV+1];     /* which vertices have been processed */
bool discovered[MAXV+1];    /* which vertices have been found */
int parent[MAXV+1];         /* discovery relation */

int entry_time[MAXV+1];     /* time of vertex entry */
int exit_time[MAXV+1];      /* time of vertex exit */
int time;                   /* current event time */

bool finished = FALSE;      /* if true, cut off search immediately */

void initialize_search(graph *g)
{
  int i;          /* counter */

  for (i=0; i<MAXV+1; ++i) {
    processed[i] = FALSE;
    discovered[i] = FALSE;
    parent[i] = -1;
  }
}

void bfs(graph *g, int start)
{
  queue q;        /* queue for save vertices */
  int v;          /* current node */
  int y;          /* neighbor vertex */
  edgenode *p;

  init_queue(&q);
  enqueue(&q, start);
  discovered[start] = TRUE;
 
  while (empty_queue(&q) == FALSE)
  {
    v = dequeue(&q);
    process_vertex_early(v);
    processed[v] = TRUE;
    p = g->edges[v];
    while (p != NULL) {
      y = p->y;
      if (processed[y] == FALSE || g->directed)
        process_edge(v, y);
      if (discovered[y] == FALSE) {
        enqueue(&q, y);
        discovered[y] = TRUE;
        parent[y] = v;
      }
      p = p->next;
    }
  }
}

int edge_classification(int x, int y)
{
  //printf("x is %d, parent[%d] = %d\n", x, y, parent[y]);
  if (parent[y] == x) return (TREE);
  if (discovered[y] && !processed[y]) return (BACK);
  if (processed[y] && (entry_time[y] > entry_time[x])) return (FORWARD); // y is the descendant of x
  if (processed[y] && (entry_time[y] < entry_time[x])) return (CROSS); // y has been processed before processing x

  printf("Warning: self loop (%d,%d)\n", x, y);
}

void dfs(graph *g, int v)
{
  edgenode *p;        /* temporary pointer */
  int y;              /* successor vertex */

  if (finished) return;   /* allow for search termination */

  discovered[v]= TRUE;
  ++time;            // time = time + 1
  entry_time[v] = time;

  process_vertex_early(v);

  p = g->edges[v];
  while (p != NULL){
    y = p->y;
    if (discovered[y] == FALSE) {
      parent[y] = v;
      //printf("parent[%d]=%d\n", y, v); // if you test articulaiton, you may need this
      process_edge(v, y);
      dfs(g, y);
    } else if((!processed[y]) || (g->directed)) {
      process_edge(v, y);
    }
    
    if (finished) return ;
    p = p->next;
  }

  process_vertex_late(v);

  ++time;
  exit_time[v] = time;
  processed[v] = TRUE;
}

void find_path(int start, int end, int parents[])
{
  if ((start == end) || (end == -1)) {
    printf("\n%d", start);
  } else {
    find_path(start, parents[end], parents);
    printf(" %d", end);
  }
}

