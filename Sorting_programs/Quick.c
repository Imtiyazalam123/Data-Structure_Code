
int quick(int A[], int l, int u) {

          int temp, left, right, loc;
          left = loc = l;
          right = u;
          while(left < right) {
                    while(left < right && A[loc] < A[right])
                              right --;
                    if(left == right)
                              break;
                  else {
                              temp = A[loc];
                              A[loc] = A[right];
                              A[right] = temp;
                              loc = right;
                    }

                     while(right > left && A[loc] > A[left])
                              left ++;
                    if(left == right)
                              break;
                    else {
                              temp = A[loc];
                              A[loc] = A[left];
                              A[left] = temp;
                              loc = left;
                    }
          }
          return loc;
}
void quick_sort(int A[], int l, int u){

          int loc;
          loc = quick(A, l, u);
          if(l < loc - 1)
                    quick_sort(A, l, loc - 1);
          if(loc + 1 < u)
                    quick_sort(A, loc+1, u);
}
