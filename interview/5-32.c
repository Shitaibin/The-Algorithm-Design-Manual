#include <stdio.h>
#include <stdlib.h>
#include "../item.h"
#include "../tree.h"

tree * insert_tree(tree *r, item_type x)
{
  tree *p;

  if (r == NULL) {
    p = (tree*) malloc(sizeof(tree));
    p->item = x;
    p->left = p->right = NULL;
    return p;
  }

  if (x < r->item)
    r->left = insert_tree(r->left, x);
  else if(x > r->item)
    r->right = insert_tree(r->right, x);
  
  return r;
}

void print_tree(tree *r)
{
  if (r == NULL)  return;

  if (r->left)
    print_tree(r->left);
  
  printf("%d ", r->item);

  if(r->right)
    print_tree(r->right);
}  

tree * read_tree(int n)
{
  int i;
  int x;
  tree *r = NULL;

  for (i=0; i<n; ++i) {
    scanf("%d", &x);
    r = insert_tree(r, x);
  }

  return r;
}

void find_ith(tree *r, int i, int *n)
{
  if (r == NULL) return ;

  find_ith(r->left, i, n);
  (*n)++;
  if (i == *n) {
    printf("\n%d-th:%d\n", i, r->item);
  } else if (i >= *n) {
    find_ith(r->right, i, n);
  }
}

int main()
{
  int n;
  tree *t;
  int i, cur;

  scanf("%d", &n);
  t = read_tree(n);
  print_tree(t);
  printf("\n");

  printf("input i: ");
  scanf("%d", &i);
  cur = 0;
  find_ith(t, i, &cur);

  return 0; 
}
