#include<stdio.h>

struct temp {
          int a;
};

int main(){

          struct temp *i;
          i->a = 5;
          printf("%d", i->a);
          return 0;
}
