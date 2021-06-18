#include<conio.h>

void insertionSort(int A[], int size) {

          int temp, i, j;
          for(i = 1; i <= size-1; i++) {

                    temp = A[i];
                    for(j = i -1; j >= 0; j--)  {
                              if(A[j] > temp)
                                        A[j+1] = A[j];
                              else
                                        break;
                    }
                    A[j + 1] = temp;
          }
}
void display(int *p, int s) {

          for(int i = 0; i < s; i++){
                    printf("%d, ", *(p+i));
          }
}
int main() {

          int arr[] = {20, 10, 1, 9, 12};
          insertionSort(arr, 5);
          display(arr, 5);
          return 0;
}
