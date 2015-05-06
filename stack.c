/*    stack.c
 *
 *    Implementation of a LIFO stack abstract data type.
 *
 *    by: Steven Skiena
 *
 *    2015-05-06 12:58
 *    Altered by James Shi
 */


#include "stack.h"
#include "bool.h"

void init_stack(stack *s)
{
  s->top = -1;
  s->count = 0;
}

void push(stack *s, int x)
{
  if (s->count >= STACKSIZE)
    printf("Warning: stack overflow push x=%d\n", x);
  else {
    s->top = s->top + 1; //++(s->top);
    s->s[s->top] = x;
    s->count = s->count + 1; //++(s->count);
  }
}

void pop(stack *s)
{
  int x;

  if (s->count <= 0)
    printf("Waring: empty stack pop.\n");
  else {
    x = s->s[s->top];
    --(s->top);
    --(s->count);
  }

  return x;
}

int empty_stack(stack *s)
{
  return 0 >= s->count;
}

void print_stack(stack *s)
{
  int i;

  for (i=(s->top); i>=0; --i)
    printf("%d ", s->s[i]);

  printf("\n");
}

