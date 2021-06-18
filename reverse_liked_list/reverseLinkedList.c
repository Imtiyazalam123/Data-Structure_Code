#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

struct node {

          int item;
          struct node *next;
};

void insertAtFirst(struct node **start, int data ) {

          struct node *n;
          n = malloc(sizeof(struct node));
          n->item = data;
          n->next = *start;
          *start = n;
}
// reverse Linked list item function
void reverseList(struct node **start) {

          struct node *s, *last, *secondLast;
          secondLast = NULL;
          last = NULL;
          s = *start;
          while(s != NULL) {
                    last = s->next;
                    s->next = secondLast;
                    secondLast  = s;
                    s = last;
          }
          *start = s;
}
void viewList(struct node *start) {

          if(start == NULL)
                    printf("there is no item for view.......");
          else {
                    while(start != NULL) {
                              printf(" %d", start->item);
                              start = start->next;
                    }
          }
}
int main() {

          struct node *start = NULL;
          insertAtFirst(&start, 10);
          insertAtFirst(&start, 11);
          insertAtFirst(&start, 5);
          insertAtFirst(&start, 41);
          viewList(start);
          reverseList(&start);
          printf("\n");
          viewList(start);
          return 0;
}
