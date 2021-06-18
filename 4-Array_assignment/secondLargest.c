#include<stdio.h>
#include<stdlib.h>

int main() {

          int size, A[size];
          int i, sl;
          printf("\n Enter Size of an Array : ");
          scanf("%d", &size);
          printf("\n Enter the values of array : ");
          for(i = 0; i < size; i++)
                    scanf("%d", &A[i]);
          sl = secondLargest(A, size);
          printf("Second Largest Value is : %d", sl);
}
int secondLargest(int A[], int size) {

      int i;
      int largest = 0;
      int secondLargest = 0;
      for(i = 0; i < size; i++) {
          if(A[i] > largest) {
                    secondLargest = largest;
                    largest = A[i];
          }
          else if(A[i] > secondLargest && A[i] != largest)
                    secondLargest = A[i];
      }
       return secondLargest;
}
