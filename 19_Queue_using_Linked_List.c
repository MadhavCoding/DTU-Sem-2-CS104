#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node* next;
};

struct Queue
{
    struct node* front;
    struct node* rear;
};

void initialise (struct Queue * Q)
{
    Q->front = NULL;
    Q->rear = NULL;
}

int isEmpty (struct Queue Q)
{
    if (Q.front == NULL) return 1;
    return 0;
}

void Push (struct Queue* Q, int x)
{
    struct node* p = (struct node*) malloc (sizeof(struct node));
    p->data = x;
    p->next = NULL;
    if(isEmpty(*Q))
    {
        Q->front = p;
        Q->rear = p;
        return;
    }
    Q->rear->next = p;
    Q->rear = p;
}

void Pop (struct Queue* Q)
{
    if(isEmpty(*Q)) return;
    struct node* p = Q->front;
    Q->front = Q->front->next;
    if(Q->front == NULL) Q->rear = NULL;
    free(p);
}

void Display (struct Queue* Q)
{
    printf("Elements of the Queue are:\n");
    struct node* q = Q->front;
    while (q != NULL)
    {
        printf("%d ", q->data);
        q = q->next;
    }
    printf("\n");
}

void Push1 (struct Queue* Q)
{
    int x;
    printf("Enter the Element you want to push: ");
    scanf("%d", &x);
    Push(Q, x);
    printf("Element has been pushed\n");
}

void Pop1 (struct Queue* Q)
{
    if(isEmpty(*Q)) 
    {
        printf("Queue is Empty\n");
        return;
    }
    Pop(Q);
    printf("Element has been popped\n");
}

int main(int argc, char const *argv[])
{
    struct Queue Q;
    initialise(&Q);
    while (1)
    {
        printf("\nWhich operation do you want to perform?\n1.Push\n2.Pop\n3.Display Queue\n4.Exit\n");
        int choice;
        scanf("%d", &choice);
        if(choice==1) Push1(&Q);
        else if(choice==2) Pop1(&Q);
        else if(choice==3) Display(&Q);
        else if(choice==4) break;
        else printf("Enter a Valid Input\n");
        printf("\n");
    }
    
    return 0;
}