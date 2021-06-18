#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

struct node {

          int item;
          struct node *next;
};
void insertAtFirst(struct node **last, int data) {

          struct node *n, *t;
          n = malloc(sizeof(struct node));
          n->item = data;
          if(*last == NULL) {
                    n->next = n;
                    *last = n;
          }
          else {
                    t = *last;
                    n->next = t->next;
                    t->next = n;
          }
}
void insertAtLast(struct node **last, int data) {

          struct node *n, *t;
          n = malloc(sizeof(struct node));
          n->item = data;
          if(*last == NULL) {
                    n->next = n;
                    *last = n;
          }
          else {
                t = *last;
                n->next = t->next;
                t->next = n;
                *last = n;
          }
}
void removeLast(struct node **last) {

           struct node *r, *t;
                    t = *last;
                    if(*last == NULL)
                              printf("\n there is no item for removal.....");
                    else if(*last == t->next) {
                              *last = NULL;
                              free(t);
                    }
                    else {
                              r = *last;
                              t = t->next;
                              do {
                                        t = t->next;
                              }while(t->next != r);
                              t->next = r->next;
                              *last = t;
                              free(r);
                    }
}
void removeFirst(struct node **last){
                    struct node *r, *t;
                    t = *last;
                    if(*last == NULL)
                              printf("\n there is no item for removal.....");
                    else if(*last == t->next) {
                              *last = NULL;
                              free(t);
                    }
                    else {
                              r = t->next;
                              t->next = r->next;
                              free(r);
                    }
}
//remove specific node for the list
void removeNode(struct node **last, struct node *d) {

          struct node *start, *t;
          t = *last;
          if(*last == d)
                    *last

}
struct node* search(struct node *last, int data) {
          struct node *t;
          t = last->next;
          do {
                    if(t->item == data)
                              return t;
                    t = t->next;
          } while(t != last->next);
          return NULL;
}
void viewList(struct node *last) {

          struct node *start;
          if(last == NULL)
                    printf("\n there is no items......");
          else {
                    start = last->next;
                    do {
                              printf("%d ",start->item);
                              start = start->next;
                    }while(start != last->next);
          }
}
int main()
{
          struct node *s, *last = NULL;

          insertAtFirst(&last, 11);
          insertAtFirst(&last, 9);
          insertAtFirst(&last, 15);

          insertAtLast(&last, 3);
          insertAtLast(&last, 5);
          //removeFirst(&last);
          //removeLast(&last);
          viewList(last);
          s = search(last, 5);
          printf("\n your item %d is available at address %u", s->item, s);

          return 0;
}
