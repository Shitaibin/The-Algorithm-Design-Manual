/*    subsets.c
 *
 *    Construct all subsets via backtracking
 *
 *    by: Steven Skiena
 *
 *    2015-05-30 18:51
 *    Altered by James Shi
 */

#include <stdio.h>
#include "bool.h"
#include "backtrack.h"

int nsol;           /* solution count */
int aryset[NMAX+1];     /* originnal set array */

void read_aryset(int n)
{
  int i;

  printf("Enter n numbers:\n");
  for (i=1; i<=n; ++i)
    scanf("%d", &aryset[i]);
}

void process_solution(int a[], int k)
{
  int i;

  ++nsol;
  printf("{");
  for (i=1; i<=k; ++i)
    if (a[i] == TRUE)
      printf(" %d", aryset[i]);
  printf(" }\n");
}

bool is_a_solution(int a[], int k, int n)
{
//  printf("solution?: %d, %d\n", k, n);
  return (k == n);
}

void make_move(int a[], int k, int n)
{
//  printf("go\n");
}

void unmake_move(int a[], int k, int n)
{
//  printf("back\n");
}

void construct_candidates(int a[], int k, int n,int c[], int *ncandidates)
{
  c[0] = TRUE;
  c[1] = FALSE;
  *ncandidates = 2;
}

int main()
{
  int a[NMAX+1];        /* solution vector */
  int n;              /* set size */
  nsol = 0;           /* init solution count */
  
  printf("Enter a number n: ");
  scanf("%d", &n);
  read_aryset(n);

  backtrack(a, 0, n);
  printf("solution count: %d\n", nsol);

  return 0;
}
