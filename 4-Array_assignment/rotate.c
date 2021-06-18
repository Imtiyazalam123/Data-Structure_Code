#include<stdio.h>
#include<conio.h>

void rotate(int A[], int n, int d, int dir) {


          int i, t;

          if(dir == 1) {
                    while(d) {
                              t = A[n-1];
                              for(i = n-1; i >=1; i--)
                                        A[i] = A[i-1];
                              A[0] = t;
                              d--;
                    }

          }
          else {

                    while(d) {
                              t = A[0];
                              for(i = 0; i <= n-2; i++)
                                        A[i] = A[i + 1];
                              A[n-1] = t;
                              d--;
                    }
          }
}

int main() {
          int i, A[5] = {5, 8, 4, 11, 15};
          for(i = 0; i < 5; i++) {
                    printf(" %d", A[i]);
          }
          rotate(A, 5, 2, -1);
          printf("\n");
          for(i = 0; i < 5; i++) {
                    printf(" %d", A[i]);
          }
          return 0;
}
