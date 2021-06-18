#include<stdio.h>
#include<stdlib.h>
#include<conio.h>

struct node {

          struct node *prev;
          int item;
          struct node *next;
};
void insertAtFirst(struct node **start, int data) {

          struct node *t, *n;
          n = malloc(sizeof(struct node));
          n->item = data;
          if(*start == NULL) {
                    n->next = n;
                    n->prev = n;
                    *start = n;
          }
          else {
                    t = *start;
                    n->next = t;
                    n->prev = t->prev;
                    t->prev->next = n;
                    t->prev = n;
                    *start = n;
          }
}
void insertAtLast(struct node **start, int data) {

          struct node *t, *n;
          n = malloc(sizeof(struct node));
          n->item = data;
          if(*start == NULL) {
                    n->next = n;
                    n->prev = n;
                    *start = n;
          }
          else {
                    t = *start;
                    n->next = t->prev->next;
                    n->prev = t->prev;
                    t->prev->next = n;
                    t->prev = n;
          }
}
void removeFirst(struct node **start) {
          struct node *t, *r;
          t = *start;
          if(*start == NULL)
                    printf("\n there is no item for perform removal operation............");
          else if(*start == t->prev && *start == t->next){
                    *start = NULL;
                    free(t);
          }
          else{
                    r = t->next;
                    r->prev = t->prev;
                    r->prev->next = r;
                    *start = r;
                    free(t);

          }
}
void removeLast(struct node **start) {
          struct node *t, *l;
          t = *start;
          if(*start == NULL)
                    printf("\n there is no item for perform removal operation............");
          else if(*start == t->prev && *start == t->next){
                    *start = NULL;
                    free(t);
          }
          else{
                    l = t->prev;
                    t->prev = l->prev;
                    l->prev->next = t;
                    free(l);
          }
}
//Remove a Specific node fro the list
void removeNode(struct node **start, struct node *d) {

          struct node *t;
          t = *start;
          if(*start == t->prev && *start == t->next){
                    if(*start == d){
                              *start = NULL;
                              free(t);
                    }
          }
          else{
                    do {
                              if(t == d){
                                        t->prev->next = t->next;
                                        t->next->prev = t->prev;
                                        free(t);
                                        break;
                              }
                              t = t->next;
                    } while(t != *start);
          }
}
struct node * search(struct node *start, int data) {
          struct node *t;
          t = start;
          do{
                    if(t->item == data)
                              return t;
                    t = t->next;
          }while(start != t);
          return NULL;
}
void viewList(struct node *start) {

          struct node *t;
          t = start;
          if(start == NULL)
                    printf("\n there is no item to view...........");
          else {
                   do {
                              printf(" %d", t->item);
                              t = t->next;
                    }while(start != t);
          }
}
int menu() {

          int choice;
          printf("\n 1. Insert At First press 1");
          printf("\n 2. Insert At Last press 2");
          printf("\n 3.  Remove from First press 3");
          printf("\n 4.  Remove from Last press 4");
          printf("\n 5.  For exit press 5");
          printf("\n\n Enter Choice");
          scanf("%d", &choice);
          return choice;
}
int main(){
          struct node *s, *start = NULL;
          int data;

          while(1) {
                    system("cls");
                    viewList(start);
                    switch(menu()) {

                              case 1 :
                                        printf("\n Enter item value for insert at first");
                                        scanf("%d", &data);
                                        insertAtFirst(&start, data);
                                        break;
                              case 2 :
                                        printf("\n Enter item value for insert at last");
                                        scanf("%d", &data);
                                        insertAtLast(&start, data);
                                        break;
                              case 3 :
                                        removeFirst(&start);
                                        break;
                              case 4 :
                                        removeLast(&start);
                                        break;
                              case 5 :
                                        exit(0);
                              default :
                                        printf("\n invalid choice please enter valid choice.......");
                    }
                  //  getch();
          }
          return 0;
}
