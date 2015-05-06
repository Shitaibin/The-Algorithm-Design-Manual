#include <stdio.h>
#include "bool.h"
#include "stack.h"

stack s;

int main()
{
  int i;
  
  init_stack(&s);

  for (i=1; i<= 10; ++i)
    push(&s ,i);

  print_stack(&s);

  return 0;
}
