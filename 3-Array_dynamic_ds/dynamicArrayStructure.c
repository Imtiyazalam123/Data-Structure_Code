#include<stdio.h>
#include<stdlib.h>

struct ArrayADT {

          int capacity;
          int lastIndex;
          int *ptr;
};

struct ArrayADT * createArray(int cap) {

          struct ArrayADT *arr;
          arr = malloc(sizeof(struct ArrayADT));
          arr-> ptr = malloc(cap * sizeof(int));
          arr->lastIndex = -1;
          arr->capacity = cap;
          return arr;
}
 //this function execute when array will be full to increase size of array two times with previous array size(2 * previous array size)
void DoubleArray(struct ArrayADT *arr, int cap) {

     //using realloc
         arr->ptr = realloc(arr->ptr, cap * sizeof(int));
         arr->capacity = cap;

       /*  //using malloc
         int i;
         int *temp;
         temp = malloc(cap * sizeof(int));
         for(i = 0; i <= arr->lastIndex; i++)
                    temp[i] = arr->ptr[i];
         free(arr->ptr);
         arr->ptr = temp;
         arr->capacity = cap;
         free(temp);  */
}
void append(struct ArrayADT *arr ,int data) {

          if(arr->lastIndex == arr->capacity - 1) {
                    DoubleArray(arr, arr->capacity * 2);
                    append(arr, data);
          }
          else {
                    arr->lastIndex += 1;
                    arr->ptr[arr->lastIndex] = data;
          }
}

 void halfArray(struct ArrayADT *arr, int cap) {

          int i;
          int *temp;
          temp = malloc(cap * sizeof(int));
          for(i = 0; i <= arr->lastIndex; i++)
                    temp[i] = arr->ptr[i];
          free(arr->ptr);
          arr->ptr = temp;
          arr->capacity = cap;
          free(temp);
 }

void insert(struct ArrayADT *arr, int index, int data) {

          int i;
          if(arr->lastIndex < 0 || index > arr->lastIndex + 1)
                    printf("\n Invalid Index.......");
          else if(arr->lastIndex == arr->capacity-1) {
                   DoubleArray(arr, arr->capacity * 2);
                   insert(arr, index, data);

          }
          else {
                    for(i = arr->lastIndex; i >= index; i--)
                              arr->ptr[i + 1] = arr->ptr[i];

                    arr->lastIndex += 1;
                    arr->ptr[index] = data;
          }
}
void removeItem(struct ArrayADT *arr, int index) {

          if(index < 0 || index > arr->lastIndex)
                    printf("\n invalid index... please give valid index for remove");
          else {
                 for(int i = index; i < arr->lastIndex ; i++)
                    arr->ptr[i] = arr->ptr[i+1];

                 arr->lastIndex -= 1;
          }
          if(arr->lastIndex < arr->capacity/2)
                    halfArray(arr, arr->capacity/2);
}
int count(struct ArrayADT *arr) {

          return arr->lastIndex + 1;
}
void editItem(struct ArrayADT *arr, int index, int data) {

          if(index < 0 || index > arr->lastIndex)
                    printf("\n Invalid Index....");
          else
                    arr->ptr[index] = data;
}

int getItem(struct ArrayADT *arr, int index){

          if(index < 0 || index > arr->lastIndex)
                    printf("\n invalid index... Please enter valid index..");
          else
                    return arr->ptr[index];
}

void display(struct ArrayADT *arr) {

          for(int i = 0; i <= arr->lastIndex; i++)
                    printf("%d, ", arr->ptr[i]);
}

void freeMemory(struct ArrayADT *arr) {

          free(arr->ptr);
          free(arr);
}
int main() {

          struct ArrayADT *arr;
          arr = createArray(3);
          append(arr, 10);
          append(arr, 15);
          append(arr, 8);
          append(arr, 20);
          append(arr, 25);
           insert(arr, 2, 12);
          removeItem(arr, 1);
          //removeItem(arr, 3);
          display(arr);
          printf("\n total capacity = %d", arr->capacity);

          freeMemory(arr);
          return 0;
}
