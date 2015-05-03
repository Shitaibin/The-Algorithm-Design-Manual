#include <stdio.h>
#include <stdlib.h>

typedef struct {
  int row;
  int col;
} point;

point *find_position(int M[3][3], int n, int m, int key)
{
  int row, col;
  point *ptr = (point *)malloc(sizeof(point)); 

  row = 0;
  col = m-1;
  while (row < n && col >= 0) {
    if (M[row][col] == key) {
      ptr->row = row;
      ptr->col = col;
      return ptr;
    } else if (M[row][col] > key) {
      col--;
    } else {
      row++;
    }
  }
  return NULL;
}

int main()
{
  int a[3][3] = {{1, 3, 5}, {4, 6, 7}, {5, 7, 8}};
  int n, m;

  n = m = 3;
  point *p;

  p = find_position(a, n, m, 4);
  if (p)
    printf("Point %d at (%d,%d)\n", 4, p->row, p->col);
  else
    printf("Can not find point %d", 4);

  return 0;
}
