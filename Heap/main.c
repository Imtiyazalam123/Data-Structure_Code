int main()
{
    int i , j, data, a[] = {100, 20, 90, 150, 70, 30, 10, 140, 80,120, 40, 60, 110, 50, 130};
    int size = 15, Heap[100], heapSize = 0;

    for(i = 0; i < size; i++)
          insert_in_heap(Heap, &heapSize, a[i]);

    for(i = 0; i < heapSize; i++) {
          printf("%d, ", Heap[i]);
    }


  if(heapSize > 0)
          data = delete_from_heap(Heap, &heapSize);

    printf("\n");

    for(i = 0; i < heapSize; i++) {
          printf("%d, ", Heap[i]);
    }
/* //this is in pending
 heap_sort(Heap , &heapSize);

    printf("\n Sorted Array : \n");
    for(i = 0; i < heapSize; i++)
          printf("%d, ", Heap[i]); */

    return 0;
}
