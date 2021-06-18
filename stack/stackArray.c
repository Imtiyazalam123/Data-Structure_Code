#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

struct stack {

          int capacity;
          int top;
          int *ptr;
};

struct stack * createStack(int cap) {

          struct stack *s;
          s = (struct stack *) malloc(sizeof(struct stack));
          s->capacity = cap;
          s->top = -1;
          s->ptr = (int *) malloc(sizeof(int) * cap);
          return s;
}
void push(struct stack *s, int data){

          if(s->top == s->capacity-1)
                    printf("\nOverflow");
          else {
                    s->top += 1;
                    s->ptr[s->top] = data;
          }
}
int pop(struct stack *s) {

          int data;
          if(s->top == -1) {
                    printf("\n Underflow");
                    return -1;
          }
          data = s->ptr[s->top];
          s->top -= 1;
          return data;
}
void peek(struct stack *s) {

          if(s->top == -1)
                    printf("\n stack is empty");
          else
                    printf("\n %d", s->ptr[s->top]);
}
void viewStack(struct stack *s) {

          int i;
          if(s->top == -1)
                    printf("\n empty stack ");
          else{
                    for(i = s->top; i >= 0; i--)
                              printf("\n %d",s->ptr[i]);
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

          struct stack *s;
          int data;
          s = createStack(5);
          while(1) {
                    system("cls");
                    viewStack(s);
                    switch(menu()){
                              case 1:
                                        printf("\n enter data value for push in stack");
                                        scanf("%d", &data);
                                        push(s, data);
                                        break;
                              case 2 :
                                        data = pop(s);
                                        printf("%d", data);
                                        break;
                              case 3 :
                                        peek(s);
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
