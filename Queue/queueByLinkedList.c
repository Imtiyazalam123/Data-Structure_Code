#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

struct Queue
{
    struct Node *front;
    struct Node *rear;
};

int insertion( struct Queue *queue, int data )
{
    struct Node *new_node = malloc( sizeof( struct Node ) );
    int success = new_node != NULL;

    if ( success )
    {
        new_node->data = data;
        new_node->next = NULL;

        if ( queue->front == NULL )
        {
            queue->front = new_node;
        }
        else
        {
          queue->rear->next = new_node;
        }

        queue->rear = new_node;
    }

    return success;
}
void deletion(struct Queue *queue) {

          if(empty(queue))
                    printf("\n Underflow");
          else if(queue->front == queue->rear) {
                    queue->front = NULL;
                    queue->rear = NULL;
          }
          else{
                    queue->front = queue->front->next;
          }

}
int empty( const struct Queue *queue )
{
    return queue->front == NULL;
}

void viewList( const struct Queue *queue )
{
    if ( empty( queue ) )
    {
        printf("\n there is no item for view...............");
    }
    else
    {
        for ( struct Node *current = queue->front; current != NULL;  current = current->next )
        {
            printf( " %d",  current->data );
        }
    }
}

int main(void)
{
    struct Queue queue = { .front = NULL, .rear = NULL };

    insertion( &queue, 5 );
    insertion( &queue, 10 );
     insertion( &queue, 15 );
    deletion(&queue);
      insertion( &queue, 10 );
      deletion(&queue);
    viewList(&queue );

    return 0;
}
