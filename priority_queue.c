/*  priority_queue.c
 *
 *  Implementation of a heap / priority queue abstract data type
 *
 *  by: Steven Skiena, James Shi
 */

#include "priority_queue.h"
#include "bool.h"

void pq_init(priority_queue *q)
{
  q->n = 0;
}

int pq_parent(int n)
{
  if (n == 1) return -1;
  else return ((int)n/2);
}

int pq_young_child(int n)
{
  return 2*n;
}

void bubble_up(priority_queue *q, int p)
{
  if (pq_parent(p) == -1) return; /* at the root of the heap */

  if (q->q[pq_parent(p)] > q->q[p]) {
    pq_swap(q, p, pq_parent(p));
    bubble_up(q, pq_parent(p));
  }
}

void bubble_down(priority_queue *q, int p)
{
  int c;              /* child index */
  int i;              /* counter */
  int min_index;      /* index of lightest child */

  c = pq_young_child(p);
  min_index = p;

  for (i=0; i<=1; i++)
    if ((c+i) <= q->n) {
      if (q->q[min_index] > q->q[c+i]) min_index = c+i;
    }

  if (min_index != p) {
    pq_swap(q, p, min_index);
    bubble_down(q, min_index);
  }
}

void pq_insert(priority_queue *q, item_type x)
{
  if (q->n >= PQ_SIZE)
    printf("Warning: priority queue overflow insert x=%d\n", x);
  else {
    q->n = (q->n) + 1;
    q->q[q->n] = x;
    bubble_up(q, q->n);
  }
}

void pq_swap(priority_queue *q, int x, int y)
{
  int t;
  
  t = q->q[x];
  q->q[x] = q->q[y];
  q->q[y] = t;
}

item_type extract_min(priority_queue *q)
{
  int min = -1;

  if (q->n <= 1) 
    printf("Warning: empty priority queue.\n");
  else {
    min = q->q[1];
    pq_swap(q, 1, q->n);
    q->n = q->n - 1;
    bubble_down(q, 1);
    return min;
  }
}

bool empty_pq(priority_queue *q)
{
  return q->n == 0;
}

void print_pq(priority_queue *q)
{
  int i;

  for (i=1; i<= q->n; i++)
    printf("%d ", q->q[i]);

  printf("\n");
}


void make_heap(priority_queue *q, item_type s[], int n)
{
  int i;

  q->n = n;
  for (i=0; i<n; i++)
    q->q[i+1] = s[i];

  for (i=q->n; i>=1; i--)
    bubble_down(q, i);

}

void make_heap1(priority_queue *q, item_type s[], int n)
{
  int i;

  pq_init(q);
  for (i=0; i<n; i++)
    pq_insert(q, s[i]);

}
