/*    set_union.h
 *
 *    Header file for union-find data structure implementation
 *
 *    2015-05-12 00:17
 *    Altered by James Shi
 */

#define SET_SIZE      1000

typedef struct {
  int p[SET_SIZE+1];    /* parent element */
  int size[SET_SIZE+1]; /* no. of elements in subtree i */
  int n;                /* no. of elements in set */
} set_union;
