#include <stdio.h>
#define MAXNUM 20

struct Queue
{
    int front;
    int rear;
    int arr[MAXNUM];
};

void initialise (struct Queue * q)
{
    q->front = 0;
    q->rear = 0;
}

int isFull (struct Queue q)
{
    if ((q.rear+1)%MAXNUM == q.front) return 1;
    return 0;
}

int isEmpty (struct Queue q)
{
    if (q.front == q.rear) return 1;
    return 0;
}

void Push (struct Queue* q)
{
    if(isFull(*q)) 
    {
        printf("Queue is Full\n");
        return;
    }
    int x;
    printf("Enter the element to be inserted : ");
    scanf("%d", &x);
    q->arr[q->rear] = x;
    q->rear = (q->rear + 1)%MAXNUM;
    printf("%d is inserted\n", x);
}

int Pop (struct Queue *q)
{
    if(isEmpty(*q))
    {
        printf("Queue is Empty\n");
        return -1;
    }
    int x = q->arr[q->front];
    q->front = (q->front + 1)%MAXNUM;
    printf("%d is deleted\n", x);
    return x;
}

void Display (struct Queue q)
{
    printf("Elements of the Queue are :-\n");
    int i = q.front; 
    int j = q.rear;
    for (; i != j; i = (i+1)%MAXNUM)
    {
        printf("%d ", q.arr[i]);
    }
    printf("\n");
}

int main(int argc, char const *argv[])
{
    struct Queue q;
    initialise(&q);
    while (1)
    {
        printf("\nWhich operation do you want to perform?\n1.Push\n2.Pop\n3.Display Queue\n4.Exit\n");
        int choice;
        scanf("%d", &choice);
        if(choice==1) Push(&q);
        else if(choice==2) Pop(&q);
        else if(choice==3) Display(q);
        else if(choice==4) break;
        else printf("Enter a Valid Input\n");
        printf("\n");
    }
    
    return 0;
}