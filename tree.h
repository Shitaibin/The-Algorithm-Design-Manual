/*    tree.h
 *    Header file for binary search tree implementation
 *    by: Steven Skiena
 *
 *    2015-05-09 17:44
 *    Altered by James Shi
 */


#include "item.h"

typedef struct tree {
  item_type item;
  struct tree *parent;
  struct tree *left;
  struct tree *right;
} tree;
