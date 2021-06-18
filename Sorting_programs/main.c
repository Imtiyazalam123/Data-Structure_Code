#include <stdio.h>
#include <stdlib.h>

int main()
{
          int i, A[] = {10, 50, 30, 20, 120, 40, 80, 70, 100, 140, 130, 110, 150, 90, 60};
          quick_sort(A, 0, 14);
          for(i = 0; i < 14; i++)
                    printf("%d ", A[i]);
    return 0;
}
