
#include <stdio.h>

#define item_type int

item_type second_largest(item_type s[], int n)
{
  item_type largest, sec_largest;
  int i;

  sec_largest = largest = s[0];
  for (i=1; i<n; i++) {
    if (s[i] > largest) {
      sec_largest = largest;
      largest = s[i];
    } else if (s[i] > sec_largest) {
      sec_largest = s[i];
    }
  }

  return sec_largest;
}

int main()
{
  item_type s[10] = {1, 3, 4, 5, 3, 4, 5, 8, 9, 9};

  item_type sec = second_largest(s, 10);

  printf("%d\n", sec);

  return 0;
}
