#include <stdio.h>
#include <stdlib.h>

int count_zero(int M[][5], int n, int m)
{
  int counter;
  int row, col;

  counter = 0;
  row = col = 0;

  while (row < n && col < m) {
    if (M[row][col] == 0) {
      counter++;
      col++;
    } else if (M[row][col] > 0) {
      col++;
    } else {
      row++;
    }
  }
  return counter;
}

int main()
{
  int n, m;
  int counter;
  int a[5][5] = {{-10, -11, -12, -15},
                 {-5, -7, -10, -11, -12},
                 {-1, -3, -4, -8, -10},
                 {1, 0, -2, -4, -5},
                 {2, 1, 0, -2, -3}};
  n = 5;
  m = 5;
  counter = count_zero(a, n, m);
  printf("There are %d zero(s)\n", counter);
  return 0;
}
