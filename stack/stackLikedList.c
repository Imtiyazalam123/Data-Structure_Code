#include<stdio.h>
#include<stdlib.h>
#include<conio.h>

struct stackNode {

          int item;
          struct stackNode *next;
};
void push(struct stackNode **start, int data) {

          struct stackNode *n;
          n = malloc(sizeof(struct stackNode));
          n->item =  data;
          n->next = *start;
          *start = n;
}
int pop(struct stackNode **start) {

          struct stackNode *t;
          int data;
          if(*start == NULL) {
                    printf("\n stack is empty......");
                    return -1;
          }
          t = *start;
          data = t->item;
          *start = t->next;
          return data;
}
void peek(struct stackNode *start){

          if(start == NULL)
                    printf("\n stack is empty.......");
          else
                    printf("\n %d", start->item);
}
void viewStack(struct stackNode *start) {

          if(start == NULL)
                    printf("\n there is no item to view because stack is empty..........");
          else {
                    while(start != NULL){
                              printf("\n %d", start->item);
                              start = start->next;
                    }
          }
}
int menu() {

          int choice;
          printf("\n 1. Push element in stack");
          printf("\n 2. Pop element from stack");
          printf("\n 3. Peek top of the element in stack");
          printf("\n 4. Exit ");
          printf("\n\n Enter Choice out of four");
          scanf("%d", &choice);
          return choice;
}
int main() {

          struct stackNode *start = NULL;
          int data;
          while(1) {
                    system("cls");
                    viewStack(start);
                    switch(menu()){
                              case 1:
                                        printf("\n enter data value for push in stack");
                                        scanf("%d", &data);
                                        push(&start, data);
                                        break;
                              case 2 :
                                        data = pop(&start);
                                        printf("\n %d", data);
                                        break;
                              case 3 :
                                        peek(start);
                                        break;
                              case 4 :
                                        exit(0);
                              default :
                                        printf("Invalid Choice.........");
                    }
                    getch();
          }
          return 0;
}
