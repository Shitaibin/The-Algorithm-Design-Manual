/*    graph.h
 *    Header file for pointer-based graph data type
 *
 *    by: Steven Skiena
 *
 *    2015-05-02 19:26
 *    Altered by James Shi
 */



#define MAXV      100
#define NULL      0

/*    DFS edge types    */

#define TREE      0
#define BACK      1
#define CROSS     2
#define FORWARD   3

typedef struct edgenode {
  int y;
  int weight;
  struct edgenode *next;
} edgenode;

typedef struct {
  edgenode *edges[MAXV+1];
  int degree[MAXV+1];
  int nvertices;
  int nedges;
  int directed;
} graph;

