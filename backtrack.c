/*    backtrack.c
 *
 *    A generic backtracking implementation
 *
 *    by: Steven Skiena
 *
 *    2015-05-30 19:00
 *    Altered by James Shi
 */

#include "backtrack.h"
#include "bool.h"

bool finished = FALSE;

void backtrack(int a[], int k, data input)
{
  int c[MAXCANDIDATES];         /* candidates for next position */
  int ncandidates;              /* next position candidates count */
  int i;


  if (is_a_solution(a, k, input))
    process_solution(a, k, input);
  else {
    ++k;
    construct_candidates(a, k, input, c, &ncandidates);
    for (i=0; i<ncandidates; ++i) {
      a[k] = c[i];
      make_move(a, k, input);
      backtrack(a, k, input);
      unmake_move(a, k, input);
      if (finished) return;
    }
  }
} 
