#include<stdio.h>
#include<stdlib.h>

struct Queue {

          int capacity;
          int front, rear;
          int *ptr;
};

struct Queue * createQueue(int cap) {

          struct Queue *q;
          q = (struct Queue *) malloc(sizeof(struct Queue));
          q->capacity = cap;
          q->front = -1;
          q->rear = -1;
          q->ptr = (int*) malloc(sizeof(int) * cap);
          return q;
}
void insertion(struct Queue *q, int data) {

          if(q->front == 0 && q->rear == q->capacity-1 || q->rear == q->front-1)
                    printf("\n Overflow");
          else if(q->rear == -1) {
                    q->rear = 0;
                    q->front = 0;
                    q->ptr[q->rear] = data;
          }
          else if(q->rear == q->capacity-1) {
                    q->rear = 0;
                    q->ptr[q->rear] = data;
          }
          else {
                    q->rear += 1;
                    q->ptr[q->rear] = data;
          }
}
void deletion(struct Queue *q) {

          if(q->front == -1)
                    printf("\n Underflow");
          else if(q->rear == q->front) {
                    q->rear = -1;
                    q->front = -1;
          }
          else if(q->front == q->capacity-1)
                    q->front == 0;
          else
                    q->front += 1;
}
int main() {
          struct Queue *q;
          q = createQueue(5);
          return 0;
}

