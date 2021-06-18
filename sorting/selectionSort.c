#include<conio.h>
#include<stdio.h>

void selectionSort(int a[],  int size) {

          int p, i, j, temp;
          for(i = 0; i < size-1; i++) {
                    p = a[i];
                    for(j = i + 1; j < size; j++)
                              if(p > a[j]) {
                                        temp = a[i];
                                        a[i] = a[j];
                                        a[j] = temp;
                              }
          }
}

//another way to implementing Selection Sort (this program coded by sir)
 /*void selectionSort(int A[], int size) {

          int i, t, index;
          for(i = 0; i <= size-2; i++) {

                    index = findMinValueIndex(A, size, i);
                    t = A[i];
                    A[i] = A[index];
                    A[index] = t;
          }
 }
 int findMinValueIndex(int A[], int size, int j) {
          int min, minIndex;
          min = A[j];
          minIndex = j;
          for(j = j+1; j <= size-1; j++)
                    if(min > A[j]) {
                              min = A[j];
                              minIndex = j;
                    }
          return minIndex;
 } */
int main() {
            int arr[] = {10, 5, 11, 12, 3};
          selectionSort(arr, 5);
          for(int i = 0; i < 5; i++)
                    printf("%d ", arr[i]);
          return 0;
}
