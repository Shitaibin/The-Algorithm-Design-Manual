#include<stdio.h>

enum color{RED = 1, WHITE, BULE};

// swap two elements depend on the indices of a array
void swap(int a[], int i, int j) 
{
    int t  = a[i];
    a[i] = a[j];
    a[j] = t;
}

// print a array
void print(int a[], int n)
{
    int i;

    for (i=0; i<n; i++)
        printf("%d ", a[i]);

    printf("\n");
}

// make sure bule_first always behind white_first
void check(int *i, int *j)
{
  int t;

  if (*j < *i) {
    t = *i;
    *i = *j;
    *j = t;
  }
}

int main()
{
    int white_first, blue_first, current;
    int a[10] = {BULE, BULE, RED, WHITE, WHITE, BULE, WHITE, BULE, RED, WHITE};
    int n = 10;

    print(a, n);

    white_first = blue_first = current = 0;
    // find the first position not RED
    for (current = 0; a[current] == RED; ++current){};
    white_first = blue_first = current;

    // if current is 
    // 1) red: swap this red with the first withe one
    //         and make sure bule always behind white
    // 2) white: swap this white with the first bule one
    // 3) bule: go next position
    while (current < n) {
        switch(a[current]) {
            case RED: 
                        swap(a, white_first++, current);
                        check(&white_first, &blue_first); break;
            case WHITE: swap(a, blue_first++, current); break;
            case BULE: ++current; break;
            default: break;
        }
    }

    print(a, n);

    return 0;
}

