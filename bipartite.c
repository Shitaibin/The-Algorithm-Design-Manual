/*    bipartite.c
 *    two color a bipartite graph
 *
 *    by: steven Skiena
 *
 *    2015-05-02 23:57
 *    Altered by James Shi
 */

#include <stdio.h>
#include "bool.h"
#include "graph.h"
#include "queue.h"

extern bool processed[];  /* which vertices have been processed */
extern bool discovered[]; /* which vertices have been found */
extern int parent[];      /* discovery relation */

extern int entry_time[MAXV+1];  /* time of vertex entry */
extern int exit_time[MAXV+1];   /* time of vertex exit */

#define UNCOLORED 0 /* vertex not yet colored */
#define WHITE   1   /* white vertex */
#define BLACK   2   /* black vertex */

int color[MAXV+1];    /* assigned color of v */
bool bipartite;       /* is the graph bipartite? */

void process_vertex_early(int v)
{
}

void process_vertex_late(int v)
{
}



void process_edge(int x, int y)
{
  // y already has a color
  if (color[x] == color[y]) {
    bipartite = FALSE;
    printf("Warning: graph not bipartite, due to (%d,%d)\n",x,y);
  } 

  color[y] = complement(color[x]);
}


void complement(int color)
{
  if (color == WHITE) return(BLACK);
  if (color == BLACK) return(WHITE);
  
  return(UNCOLORED);
}

void twocolor(graph *g)
{
  int i;        /* counter */

  for (i=1; i<=(g->nvertices); i++) 
    color[i] = UNCOLORED;

  bipartite = TRUE;
 
  initialize_search(&g);

  /* using for to dealing with unconnected graph */
  for (i=1; i<=(g->nvertices); i++) {
    if (discovered[i] == FALSE) {
      color[i] = WHITE;
      bfs(g,i);
    }
  }
}


int main()
{
  graph g;
  int i;

  read_graph(&g,FALSE);
  print_graph(&g);

  twocolor(&g);

  printf("the color of nodes\n");
  for (i=1; i<=(g.nvertices); i++)
    printf("%d: %d\n", i, color[i]);
  printf("\n");

  return 0;
}
