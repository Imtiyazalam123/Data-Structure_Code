#include<stdio.h>
#include<stdlib.h>

struct node {

          int item;
          struct node *next;
};

void insertAtLast(struct node **s, int data) {

         struct node *t, *n;
          n = malloc(sizeof(struct node));
          n->item = data;
          n->next = NULL;
          if(*s == NULL)
                    *s = n;
          else {
                    t = *s;
                    while(t->next != NULL)
                              t = t->next;
                    t->next = n;
          }
}

void insertAtStart(struct node **s, int data) {

          struct node *t, *n;
          n = malloc(sizeof(struct node));
          n->item = data;
          n -> next = *s;
          *s = n;

         /* we can use this after commenting line 31 to 32
          n->next = NULL;
          if(*s == NULL)
                    *s = n;
          else {
                   t = *s;
                   n->next = t;
                   *s = n;
          } */
}

void insertAfter(struct node *after, int data) {

          struct node *n;
          n = malloc(sizeof(struct node));
          n->item = data;
          n->next = after->next;
          after->next = n;
}
void removeFirst(struct node **s) {

          struct node *t;
          if(*s == NULL)
                    printf("\n there is a no item. how can u delete.......");
          else {
                    t = *s;
                    *s = t->next;
                    free(t);
          }
}
void removeLast(struct node **s) {

          struct node *t1, *t2;
          if(*s == NULL)
                    printf("\n nothing to delete.....");
          else {

                t1 = *s;
                t2 = NULL;
                while(t1->next != NULL) {
                    t2 = t1;
                    t1 = t1->next;
                }
                if(t2 != NULL)
                    t2->next = NULL;
                else
                    *s = NULL;
                free(t1);
          }

}
void removeNode(struct  node **s, struct node *r ) {

          struct node *t;
          if(*s == r)
                    *s = r->next;
          else {
                    t = *s;
                    while(t->next != r)
                              t = t->next;
                    t->next = r->next;
          }
           free(r);
}
 struct node * search(struct node *start, int data) {

          while(start) {
                    if(start->item == data)
                              return start;
                   start = start->next;
          }
          return NULL;
 }
int main() {

          struct node *start = NULL;
          insertAtLast(&start, 30);
          return 0;
}

