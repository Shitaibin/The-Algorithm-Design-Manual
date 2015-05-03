#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
#include <string>
#include <vector>
#include <queue>
#include "item.h"
#include <time.h>

/*          Sorts                 */
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

/*                read and write file                   */

void read_words(std::vector<item_type> &buffer, std::string fname)
{
  std::ifstream ifs;
  ifs.open(fname, std::ifstream::in);
  buffer.clear();
  std::string word;
  while (!ifs.eof()) {
    ifs >> word;
    if (word.size()) buffer.push_back(word);
    word.clear();
  }; 
  ifs.close();
}

void write_words(std::vector<item_type> &words, std::string fname)
{
  std::ofstream ofs;
  ofs.open(fname, std::ofstream::out);
  for (std::vector<item_type>::iterator it = words.begin(); it!=words.end(); ++it) {
    ofs << *it << " ";
  }
  ofs << std::endl;
  ofs.close();
}


void print_time(std::vector<time_t> s, std::vector<time_t> e)
{
  int i;
  for(i=0; i<s.size();++i) {
    std::cout << s[i] << "\t" << e[i] << "\t" << e[i] - s[i] << std::endl;
  }
}

int main()
{
  time_t start, stop;
  std::vector<time_t> starts, stops;

  std::vector<item_type> words;
  
  std::string fn;
  std::cout << "Input file name: ";
  std::cin >> fn;
  read_words(words, fn);  

  std::cout << "Original words:" << std::endl;
  //print_vector(words);
  std::cout << std::endl;

  
  std::cout << "heapsort:" << std::endl;
  std::vector<item_type> heap_words(words);
  time(&start);
  heapsort(heap_words);
  time(&stop);
  starts.push_back(start);
  stops.push_back(stop);
  //print_vector(heap_words);
  std::cout << std::endl;
  write_words(heap_words, "heap_words");
  std::vector<item_type>().swap(heap_words);

  std::cout << "mergesort:" << std::endl;
  std::vector<item_type> merge_words(words);
  time(&start);
  mergesort(merge_words);
  time(&stop);
  starts.push_back(start);
  stops.push_back(stop);
  //print_vector(merge_words);
  std::cout << std::endl;
  write_words(merge_words, "merge_words");
  std::vector<item_type>().swap(merge_words);

  std::cout << "quicksort:" << std::endl;
  std::vector<item_type> quick_words(words);
  time(&start);
  quicksort(quick_words, 0, quick_words.size()-1);
  time(&stop);
  starts.push_back(start);
  stops.push_back(stop);
  //print_vector(quick_words);
  std::cout << std::endl;
  write_words(quick_words, "quick_words");
  std::vector<item_type>().swap(quick_words);
  
  std::cout << "sort:" << std::endl;
  std::vector<item_type> sort_words(words);
  time(&start);
  std::sort(sort_words.begin(), sort_words.end());
  time(&stop);
  starts.push_back(start);
  stops.push_back(stop);
  //print_vector(sort_words);
  std::cout << std::endl;
  write_words(sort_words, "sort_words");
  std::vector<item_type>().swap(sort_words);
  
  print_time(starts, stops);

  return 0;
}
