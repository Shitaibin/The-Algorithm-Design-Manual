// Wether the kth smallest element in the heap is greater than or
// equal to x.

// This function only visit those elements less than x, and visit
// their childs. So it will most visit 3k nodes, for a total time
// of O(k).

// This question can be asked in this way. The number of nodes 
// which less than x is greater than k. If yes, it will return 0,
// or return a positive number.
int heap_compare(priority_queue *q, int i, int count, int x)
{
  if ((count <= 0) || (i > q->n)) return count;

  if (q->q[i] < x) {
    count = heap_compare(q, pq_young_child(i), count-1, x);
    count = heap_compare(q, pq_young_child(i)+1, count, x);
  }

  return count;
}
