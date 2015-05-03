/* divid a 2n array into two parts
 * all number in first part smaller than any number in the sencond part
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

void quicksort(int s[], int l, int h, int middle)
{
  int p;

  if (h  > l) {
	  p = partition(s, l, h);
	  if (p == middle) return ;
    else if (p > middle) quicksort(s, l, p-1, middle);
    else quicksort(s, p+1, h, middle);
  }
}

int main()
{
  int i;
  int middle;
  int rate[10] = {3, 4, 9, 5, 2, 1, 8, 7, 10, 6};

  middle = 4;
  quicksort(rate, 0, 9, middle);

  printf("first part: ");
  for (i=0; i<=middle; i++)
    printf("%d ", rate[i]);

  printf("\nsecond part: ");
  for (i=middle+1; i<10; i++)
    printf("%d ", rate[i]);

  puts("");
  return 0;
}
