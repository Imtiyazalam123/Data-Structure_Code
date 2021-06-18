#include<stdio.h>
#include<conio.h>

void TOH(int n, char beg, char aux, char end) {
         if(n > 0) {
                    TOH(n-1, beg, end, aux);
                    printf("%c -> %c \n", beg, end);
                    TOH(n-1, aux, beg, end);
         }
}
int main() {

          TOH(3,'A', 'B', 'C');
          return 0;
}
