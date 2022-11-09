#include <stdio.h>
#include <stdlib.h>

#define QUEUE_MAX 10

typedef struct Queue {
    int items[QUEUE_MAX];
    int front;
    int rear;
} qu;

void initializeQueue(qu *qu_p);

void enqueue(qu *qu_p, int item);
void dequeue(qu *qu_p);

int peek(qu *qu_p);

int main()
{
    qu *qu_p = (qu*) malloc(sizeof(qu));
    initializeQueue(qu_p);

    return 0;
}

void initializeQueue(qu *qu_p)
{
    qu_p->front = -1;
    qu_p->rear = -1;
}

void enqueue(qu *qu_p, int item)
{
    if(qu_p->rear == QUEUE_MAX - 1)
    {
        printf("[OPERATION \"enqueue()\" CANNOT BE EXECUTED: QUEUE IS FULL]\n");
        return;
    }
    else if(item <= 0)
    {
        printf("[OPERATION \"enqueue()\" CANNOT BE EXECUTED: NUMBER MUST BE POSITIVE]\n");
        return; 
    }

    if(qu_p->front == -1 && qu_p->rear == -1)
    {
        qu_p->front = 0;
        qu_p->rear = 0;
        qu_p->items[qu_p->rear] = item;
        return;
    }


    qu_p->rear++;
    qu_p->items[qu_p->rear] = item;
}

void dequeue(qu *qu_p)
{
    if
    (
        qu_p->front == -1 || 
        qu_p->front == QUEUE_MAX - 1
    )
    {
        printf("[OPERATION \"dequeue()\" CANNOT BE EXECUTED: QUEUE IS EMPTY]\n");
        return;
    }

    else if(qu_p->front == qu_p->rear)
    {
        qu_p->front = -1;
        qu_p->rear = -1;
        return;
    }

    qu_p->front++;
}

int peek(qu *qu_p)
{
    if(qu_p->front == -1)
    {
        printf("[OPERATION \"peek()\" CANNOT BE EXECUTED: QUEUE IS EMPTY]\n");
        return -1;
    }
    else 
    {
        return qu_p->items[qu_p->front];
    }
}