int linear_search(int A[], int size, int item) {

          int index;
          for(index = 0; index < size; index++)
                    if(A[index] == item)
                              return index;
          return -1;
}

int binary_search(int A[], int l, int u, int item) {

          int m ;
          if(l <= u) {
                    m = (l+u)/2;
                    if(A[m] == item)
                              return m;
                    if(item < A[m])
                              return binary_search(A, l, m-1, item);
                    else
                              return binary_search(A, m+1, u, item);
          }
          return -1;
}
