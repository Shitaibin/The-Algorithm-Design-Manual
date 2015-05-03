#include <stdio.h>

int find_smallest_next(int a[], int l, int h)
{
  int mid;

  mid = (l+h) / 2;
  if (l == h)
    return l;

  if (a[mid] > mid+1)
    return find_smallest_next(a, l, mid);
  else
    return find_smallest_next(a, mid+1, h);
}

int find_smallest(int a[], int n)
{
  int next;

  next = find_smallest_next(a, 0, n-1);
  return a[next-1] + 1;
}

void print(int a[], int n)
{
  int i;
  for (i=0; i<n; i++)
    printf("%d ", a[i]);
  printf("\n");
}

int main()
{
  int a[10] = {1, 2, 5, 6, 7, 9, 10, 11, 12, 14};
  int n = 10;
  int smallest;

  print(a, n);

  smallest = find_smallest(a, n);
  printf("%d\n", smallest);
  return 0;
}
