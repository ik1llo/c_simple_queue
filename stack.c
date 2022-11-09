#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define STACK_MAX 10

typedef struct Stack 
{
    int items[STACK_MAX];
    int top;
} st; 

void initializeStack(st *st_p);

bool isFull(st *st_p);
bool isEmpty(st *st_p);

void push(st *st_p, int item);
void pop(st *st_p);
int peek(st *st_p);

void printStack(st *st_p);

int main()
{
    st *st_p = (st*) malloc(sizeof(st));
    initializeStack(st_p);

    printStack(st_p);

    return 0;
}

void initializeStack(st *st_p) { st_p->top = -1; }

bool isEmpty(st *st_p)
{
    if(st_p->top == -1)
        return true;
    return false;
}

bool isFull(st *st_p)
{
    if(st_p->top == STACK_MAX - 1)
        return true;
    return false;
}

void push(st *st_p, int item)
{
    if(isFull(st_p))
    {
        printf("[OPERATION \"push()\" CANNOT BE EXECUTED: STACK IS FULL]\n");
        return;
    }

    st_p->top++;
    st_p->items[st_p->top] = item;
}

void pop(st *st_p)
{
    if(isEmpty(st_p))
    {
        printf("[OPERATION \"printStack()\" CANNOT BE EXECUTED: STACK IS EMPTY]");
        return;
    }

    st_p->top--;
}

int peek(st *st_p)
{
    if(isEmpty(st_p))
    {
        printf("[OPERATION \"peek()\" CANNOT BE EXECUTED: STACK IS EMPTY]"); 
    }

    return st_p->items[st_p->top];
}

void printStack(st *st_p)
{
    if(isEmpty(st_p))
    {
        printf("[OPERATION \"printStack()\" CANNOT BE EXECUTED: STACK IS EMPTY]"); 
    }

    for(int k = 0; k <= st_p->top; k++)
    {
        printf("%d\n", st_p->items[k]);
    }
}