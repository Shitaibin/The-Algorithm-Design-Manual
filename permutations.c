/*    permutations.c
 *
 *    Construct all permutations via backtracking
 *
 *    by: Steven Skiena
 *
 *    2015-06-01 22:37
 *    Altered by James Shi
 */

#include "bool.h"
#include "backtrack.h"
#include <stdio.h>

void process_solution(int a[], int k)
{
  int i;

  for (i=1; i<=k; ++i)  printf(" %d", a[i]);
  printf("\n");
}

// get the k-th candidates
void construct_candidates(int a[], int k, int n, int c[], int *ncandidates)
{
  int i;
  bool in_perm[NMAX];

  for (i=1; i<NMAX; ++i) in_perm[i] = FALSE;
  for (i=1; i<k; ++i)  in_perm[a[i]] = TRUE;
  *ncandidates = 0;
  for (i=1; i<=n; ++i)
    if (in_perm[i] == FALSE)
      c[(*ncandidates)++] = i;
}

bool is_a_solution(int a[], int k ,int n)
{
  return k==n;
}

void generate_permutations(int n)
{
  int a[NMAX];            /* solution vector */
  backtrack(a, 0, n);
}


void make_move(int a[], int k, int n)
{
}

void unmake_move(int a[], int k, int n)
{
}

int main()
{
  int n;

  printf("Enter a number n: ");
  scanf("%d", &n);

  printf("the permutations of list [1, ... , n]\n");
  generate_permutations(n);
  return 0;
}
