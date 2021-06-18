
#include<stdio.h>


struct temp {
          int min;
          int max;
};

void display(struct temp *tem);

int main() {

          struct temp t;
          printf("Enter min Temp : \n");
          scanf("%d", &t.min);
          printf("Enter max Temp : \n");
          scanf("%d", &t.max);
          display(&t);
          return 0;
 }
void display(struct temp *tem) {

          printf("min temp  : %d\n",tem->min );
          printf("max temp : %d\n",tem->max);
}
