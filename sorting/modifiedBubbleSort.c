#include<conio.h>
#include<stdio.h>

void modifiedBubbleSort(int a[], int size) {

          int round, j, temp, flag;
          for(round = 1; round < size; round++) {

                for(j = 0, flag = 0; j < size - round ; j++){
                    if( a[j] > a[j + 1]) {
                              flag = 1;
                              temp = a[j];
                              a[j] = a[j + 1];
                              a[j + 1] = temp;
                    }
                }
                if(flag == 0)
                    break;
          }
}
int main() {
          int arr[] = {10, 5, 11, 2, 3};
          modifiedBubbleSort(arr, 5);
          for(int i = 0; i < 5; i++)
                    printf("%d ", arr[i]);
          return 0;
}
