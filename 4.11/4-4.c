/*  sort by color
 *
 *  using qsort is easy to figure out this problem
 *
 *  by: James Shi
 *
 *  2015-04-21 19:15 
 */

#include <stdio.h>
#include <stdlib.h>

enum color { red = 1, blue, yellow};

typedef struct {
  int id;
  int color;  /* red:1, blue:2, yellow:3 */
} item;

int item_cmp(const void *x, const void *y)
{
  const item *a = (item *) x;
  const item *b = (item *) y;

  if (a->color != b->color)
    return a->color - b->color;
  else
    return a->id - b->id;
}

void color_print(int num)
{
  switch(num){
    case red: printf("red"); break;
    case blue: printf("blue"); break;
    case yellow: printf("yellow"); break;
    default: printf("no this color"); break;
  }
}

void item_print(item s[], int n)
{
  int i;

  for(i=0; i<n; i++) {
    printf("%d ", s[i].id);
    color_print(s[i].color);
    printf("\n");
  }
  printf("\n");
}


int main()
{
  int n;  
  item items[100];
 
  n = 5;
  items[0].id = 1; 
  items[0].color = blue;
  items[1].id = 3; 
  items[1].color = red;
  items[2].id = 4; 
  items[2].color = blue;
  items[3].id = 6; 
  items[3].color = yellow;
  items[4].id = 9; 
  items[4].color = red;
  item_print(items, n);

  qsort(items, n, sizeof(items[0]), item_cmp);
  item_print(items, n);

  return 0;
}
