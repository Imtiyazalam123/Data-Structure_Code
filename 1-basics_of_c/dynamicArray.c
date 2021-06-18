#include<conio.h>
#include<stdio.h>
#include<stdlib.h>

int * add(int [] , int [], int, int);
int main() {

           int i, arr1[] = {2, 5, 5, 6, 8, 10}, arr2[] = {5, 5, 6, 7, 8};


          int sizeOfA1 = sizeof(arr1)/sizeof(int);
          int sizeOfA2 = sizeof(arr2)/sizeof(int);

           int *ptr = add(arr1, arr2, sizeOfA1, sizeOfA2);

           printf("your values are : \n");
           for(i = 0; i < (sizeOfA1+sizeOfA2); i ++){
                      printf("%d ", ptr[i]);
           }
           free(ptr);
           return 0;
}
int * add(int a1[], int a2[], int sizeOfA1, int sizeOfA2) {

          int size = sizeOfA1 + sizeOfA1;

          int *p = (int*) malloc(size * sizeof(int));

           int k = 0;
          for(int i = 0; i < size; i++) {
                      if(i < sizeOfA1){
                         p[i]  = a1[i];
                      }
                      else {
                                 p[i] = a2[k];
                                 k++;
                      }
          }
          return p;
}
