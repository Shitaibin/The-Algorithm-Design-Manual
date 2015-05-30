/*    backtrack.h
 *
 *    A header file for generic backtracking
 *
 *    by: Steven Skiena
 *
 *    2015-05-30 18:56
 *    Altered by James Shi
 */

#define   MAXCANDIDATES   100       /* max possible next extensions */
#define   NMAX            100       /* maximum solution size */

typedef char* data;                 /* type to pass data to backtrack */
