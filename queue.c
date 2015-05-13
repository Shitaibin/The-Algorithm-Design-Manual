/*    queue.c
 *    Implementation of a FIFO queue abstract data type
 *
 *    by: Steven Skiena
 *
 *    2015-04-21 19:52
 *    Altered by James Shi
 *     
 */

#include "queue.h"
#include "item.h"
#include "bool.h"


void init_queue(queue *q)
{
  q->first = 0;
  q->last = QUEUESIZE-1;
  q->count = 0;
}

void enqueue(queue *q, item_type x)
{
  if (q->count < QUEUESIZE-1) {
    q->last = (q->last+1) % QUEUESIZE;
    q->q[ q->last ] = x;
    q->count = q->count + 1;
  } else {
    printf("Warning: queue overflow enqueue x=%d\n", x);
  }
}

item_type dequeue(queue *q) 
{
  item_type x;

  if (q->count <= 0) printf("Warning: empty queue dequeue.\n");
  else {
    x = q->q[ q->first ];
    q->first = (q->first+1) % QUEUESIZE;
    q->count = q->count - 1;
  }

  return x;
}

item_type headq(queue *q)
{
  return q->q[ q->first ];
}

bool empty_queue(queue *q)
{
  return q->count == 0;
}

print_queue(queue *q)
{
  int i;

  i = q->first;
  while (i != q->last) {
    printf("%d ", q->q[i]);
    i = (i+1) % QUEUESIZE;
  }
  printf("%d\n", q->q[i]);
}
