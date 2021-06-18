#include<conio.h>
#include<stdio.h>

void bubbleSort(int *arr, int size) {
          int temp, i, j;
          for(i = 1; i < size; i++){
                    for(j = 0; j <= size - i -1 ; j++){
                              if(*(arr+j) > *(arr+j+1)) {
                                   temp = *(arr+j);
                                   *(arr+j) = *(arr+j+1);
                                   *(arr+j+1)= temp;
                              }
                    }
          }
}
void display(int *p, int s) {

          for(int i = 0; i < s; i++){
                    printf("%d, ", *(p+i));
          }
}
int main() {
         int i, size;
         printf("\n Enter Array Size ....");
         scanf("%d", &size);
         if(size < 1){
                     printf("\n Invalid size please  re enter Array Size ....");
                     scanf("%d", &size);
         }
         int arr[size];
         printf("\n Enter %d array values...", size);
          for(i = 0; i < size; i++){
                    scanf("%d", &arr[i]);
          }
          bubbleSort(arr, size);
          display(arr, size);
          return 0;
}
