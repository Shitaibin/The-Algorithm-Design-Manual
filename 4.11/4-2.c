
/* 
 * 
 *
 * by: James.Shi
 */

#include <stdio.h>

void swap(int *x, int *y)
{
  int t;
  t = *x;
  *x = *y;
  *y = t;
}

int partition(int s[], int l, int h)
{
  int i;
  int p;
  int firsthigh;

  p = h;
  firsthigh = l;
  for (i=l; i<h; i++) {
    if (s[i] < s[p]) {
      swap(&s[i], &s[firsthigh]);
      firsthigh++;
    }
  }

  swap(&s[i], &s[firsthigh]);
  return firsthigh;
}

void quicksort(int s[], int l, int h)
{
  int p;

  if (h  > l) {
	  p = partition(s, l, h);
    quicksort(s, l, p-1);
    quicksort(s, p+1, h);
  }
}

void a(int s[], int n, int *x, int *y)
{
  int min, max; /*index*/
  int i;

  min = max = 0;
  for (i=0; i<n; i++) {
    min = s[min] < s[i] ? min:i;
    max = s[max] > s[i] ? max:i;
  }
  *x = s[min];
  *y = s[max];
}

void b(int s[], int n, int *x, int *y)
{
  *x = s[0];
  *y = s[n-1];
}

void d(int s[], int n, int *x, int *y)
{
  int i, min;

  min = 0;
  for (i=0; i<n-1; i++)
    min = (s[min+1]-s[min]) < (s[i+1]-s[i]) ? min : i;

  *x = s[min];
  *y = s[min + 1];
}

int main()
{
  int i;
  int S[5] = {6, 13, 19, 3, 8};
  int x, y;

  quicksort(S, 0, 5);

  d(S, 5, &x, &y);
  printf("%d %d\n", x, y);  
  
  
  quicksort(S, 0, 5);
  for (i=0; i<5; i++)
    printf("%d ", S[i]);
  puts("");
  return 0;
}
