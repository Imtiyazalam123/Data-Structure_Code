#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include "main.c"

struct ArrayADT {

          int capacity;
          int lastIndex;
          int *ptr;
};

struct ArrayADT * createArray(int cap) {

          struct ArrayADT *arr;
          arr = malloc(sizeof(struct ArrayADT));
          arr->capacity = cap;
          arr->lastIndex = -1;
          arr->ptr = malloc(sizeof(int) * cap);

          return arr;
}

void append(struct ArrayADT *arr, int data){

          if(arr->lastIndex == arr->capacity-1)
                    printf("\nOverflow");
          else {
                    arr->lastIndex += 1;
                    arr->ptr[arr->lastIndex] = data;
          }
}
void insert(struct ArrayADT *arr, int index, int data){

                    int i;
                    if(index < 0 || index > arr->lastIndex + 1)
                              printf("\n invalid index");
                    else if(arr->lastIndex == arr->capacity-1)
                              printf("\n Overflow");
                    else {
                              for(i = arr->lastIndex; index <= i;  i--) {
                                        arr->ptr[i + 1] = arr->ptr[i];
                              }
                              arr->ptr[index] = data;
                              arr->lastIndex += 1;
                    }
}
int getItem(struct ArrayADT *arr, int index) {

          if(index > 0 && index <= arr->lastIndex)
                    return arr->ptr[index];
          printf("\n invalid index");
          return -1;
}
int count(struct ArrayADT *arr){

          return arr->lastIndex+1;
}

void editItem(struct ArrayADT *arr, int index, int data) {

          if(index < 0 || index > arr->lastIndex)
                              printf("\n invalid index");
           else
                    arr->ptr[index] = data;
}
void removeItem(struct ArrayADT *arr, int index) {

            int i;
            if(index < 0 || index > arr->lastIndex)
                              printf("\n invalid index");
            else {
                    for(i = index; i < arr->lastIndex; i++)
                              arr->ptr[i] = arr->ptr[i + 1];
                    arr->lastIndex -= 1;
            }
}
int searchItem(struct ArrayADT *arr, int data) {

          int i;
          for(i = 0; i <= arr->lastIndex; i++)
                    if(arr->ptr[i] == data)
                              return i;
          return -1;
}
void displayItems(struct ArrayADT *arr){
          printf("\nYour Items are : ");
          for(int i = 0; i <= arr->lastIndex; i++) {
                    printf("%d, ",arr->ptr[i]);
          }
}
int main(){

          struct ArrayADT *arr;
          arr = createArray(6);
          append(arr, 20);
          append(arr, 15);
          append(arr, 40);
          insert(arr, 2, 10);
          int item = getItem(arr, 2);
          printf("\n Your item is in index 2 : %d", item);
          int c = count(arr);
          printf("\n total number of Items are : %d", c);
          editItem(arr, 3, 25);
          printf("\n Your item 10 is an index : %d", searchItem(arr, 10));
          removeItem(arr, 2);
          displayItems(arr);
          return 0;
}
