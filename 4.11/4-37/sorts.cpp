/*
 * 
 *    2015-05-01 11:25
 *    Altered by James Shi
 *
 *    Going to only implement heapsort, mergesort and quicksort by using STL
 */

#include "sorts.h"

//bool compare(item_type a, item_type b)
//{
//  if (a < b)  return LESS_THAN;
//  if (a > b)  return GREATER_THAN;
//  return EQUAL_TO;
//}

void swap_vector(std::vector<item_type> &v, int i, int j)
{
  item_type t;

  t = v[i];
  v[i] = v[j];
  v[j] = t;
}

void swap(item_type *x, item_type *y)
{
  item_type t;

  t = *x;
  *x = *y;
  *y = t;
}

int partition(std::vector<item_type> &v, int l, int h)
{
  int i;
  int p;
  int firsthigh;

  p = h;
  firsthigh = l;
  for (i=l; i<h; ++i) {
    if (v[i] < v[p]) {
      swap_vector(v, i, firsthigh);
      ++firsthigh;
    }
  }

  swap_vector(v, p, firsthigh);
  return firsthigh;
}

void quicksort(std::vector<item_type> &v, int l, int h)
{
  int p;

  if ((h-l) > 0) {
    p = partition(v, l, h);
    quicksort(v, l, p-1);
    quicksort(v, p+1, h);
  }
}


void print_vector(std::vector<item_type> v)
{
  int i;
  int n = v.size();

  for (i=0; i<n; i++)
   std::cout << v[i] << " ";
  
  std::cout << std::endl;
} 

struct Compare {
	bool operator()(const item_type &x, const item_type &y)
  {
   return x >  y;
  }
};

void heapsort(std::vector<item_type> &v)
{
  std::priority_queue<item_type, std::vector<item_type>, Compare> pq;
  for (std::vector<item_type>::iterator it = v.begin(); it != v.end(); ++it)
    pq.push(*it);

  v.clear();
  while (!pq.empty()) {
    v.push_back(pq.top());
    pq.pop();
  }
}

void merge(std::vector<item_type> &v, int l, int m, int h)
{
  int i;
  std::queue<item_type> buffer1, buffer2;
  for (i=l; i<=m; ++i)  buffer1.push(v[i]);
  for (i=m+1; i<=h; ++i) buffer2.push(v[i]);

  i = l;
  while (!buffer1.empty() && !buffer2.empty()) {
    if (buffer1.front() < buffer2.front()) {
      v[i++] = buffer1.front();
      buffer1.pop();
    } else {
      v[i++] = buffer2.front();
      buffer2.pop();
    }
  }

  while (!buffer1.empty()) {
    v[i++] = buffer1.front();
    buffer1.pop();
  }

  while (!buffer2.empty()) {
    v[i++] = buffer2.front();
    buffer2.pop();
  }
}

void mergesort_recu(std::vector<item_type> &v, int l, int h)
{
  int middle;

  if (l < h) {
    middle = ( l + h ) / 2;
    mergesort_recu(v, l, middle);
    mergesort_recu(v, middle+1, h);
    merge(v, l, middle, h);
  }
}

void mergesort(std::vector<item_type> &v)
{
  mergesort_recu(v, 0, v.size()-1);
}

//int main()
//{
//  std::vector<item_type> words = {"klks", "fdk", "abc", "owd"};
//  std::vector<item_type> quick_words(words);
//
//  std::cout << "Original words:" << std::endl;
//  print_vector(quick_words);
//  std::cout << std::endl;
//
//  std::cout << "quicksort:" << std::endl;
//  quicksort(quick_words, 0, quick_words.size()-1);
//  print_vector(quick_words);
//  std::cout << std::endl;
//   
//  
//  std::cout << "heapsort:" << std::endl;
//  std::vector<item_type> heap_words(words);
//  heapsort(heap_words);
//  print_vector(heap_words);
//  std::cout << std::endl;
//
//  std::cout << "mergesort:" << std::endl;
//  std::vector<item_type> merge_words(words);
//  mergesort(merge_words);
//  print_vector(merge_words);
//  std::cout << std::endl;
//
//  return 0;
//}
