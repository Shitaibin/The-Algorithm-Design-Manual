/*    queue.h
 *    Header file for queue implementation
 *
 *    by: Steven Skiena, James Shi
 *    2015-04-21 19:17 
 */

#define QUEUESIZE 1000

typedef struct {
  int /*item_type*/ q[QUEUESIZE];
  int first;
  int last;
  int count;
} queue;
