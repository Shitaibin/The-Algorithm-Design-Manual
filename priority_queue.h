/*  priority_queue.h
 *
 *  Header file for queue implementation
 *
 *  by: Steven Skina, James Shi
 */

#include "item.h"

#define PQ_SIZE 1000

typedef struct {
  item_type q[PQ_SIZE+1]; /*body of queue */
  int n;                  /* number of queue elements */
} priority_queue;
