void insert_in_heap(int Heap[], int *hs, int data) {

          int index, parIndex;
          *hs = *hs+1;

          index = *hs-1;
          while(index > 0){
                    parIndex = (index-1)/2;
                    if(data > Heap[parIndex])
                              Heap[index] = Heap[parIndex];
                    else
                              break;
                    index = parIndex;
          }
          Heap[index] = data;

}

int delete_from_heap(int Heap[], int *hs) {

          int item, temp, index, leftIndex, rightIndex;
          item = Heap[0];
          temp = Heap[*hs-1];
          *hs = *hs-1;
          index = 0;
          while(index <= *hs-1) {

              leftIndex = 2*index+1;
              rightIndex = 2*index+2;
              if(leftIndex > *hs-1)  //no child
                    break;
              if(rightIndex > *hs-1){

                    if(temp < Heap[leftIndex])
                              Heap[index] = Heap[leftIndex];
                    else
                              break;
                    index = leftIndex;
              }
              if(Heap[leftIndex] > Heap[rightIndex]) {

                    if(temp < Heap[leftIndex])
                              Heap[index] = Heap[leftIndex];
                    else
                              break;
                    index = leftIndex;
              }
              else {

                   if(temp < Heap[rightIndex])
                              Heap[index] = Heap[rightIndex];
                   else
                              break;
                   index = rightIndex;
              }
          }
          Heap[index] = temp;
          return item;

}
/* this is in pending
// self written
void heap_sort(int Heap[], int *hs) {

          int data, i, j, size;
          size = *hs;
          j = size;
          while(j > 0) {

                    data =delete_from_heap(Heap, &hs);
                    j--;
                    Heap[j] = data;
          } */

}
