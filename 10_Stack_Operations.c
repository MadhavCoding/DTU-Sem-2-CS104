#include <stdio.h>
#define MAXNUM 20

struct Stack
{
    int top;
    int arr[MAXNUM];
};

void initialise (struct Stack * s)
{
    s->top = -1;
}

int isFull (struct Stack s)
{
    if (s.top == MAXNUM-1) return 1;
    return 0;
}

int isEmpty (struct Stack s)
{
    if (s.top == -1) return 1;
    return 0;
}

void Push (struct Stack* s)
{
    if(isFull(*s)) 
    {
        printf("Stack is Full\n");
        return;
    }
    int x;
    printf("Enter the element to be inserted : ");
    scanf("%d", &x);
    s->top = s->top + 1;
    s->arr[s->top] = x;
    printf("%d is inserted\n", x);
}

int Pop (struct Stack* s)
{
    if(isEmpty(*s))
    {
        printf("Stack is Empty\n");
        return -1;
    }
    int x = s->arr[s->top];
    s->top = s->top - 1;
    printf("%d is deleted\n", x);
    return x;
}

void Display (struct Stack s)
{
    printf("Elements of the Stack are :-\n");
    for (int i = s.top; i >= 0; i--)
    {
        printf("%d ", s.arr[i]);
    }
    printf("\n");
}

int main(int argc, char const *argv[])
{
    struct Stack s;
    initialise(&s);
    while (1)
    {
        printf("\nWhich operation do you want to perform?\n1.Push\n2.Pop\n3.Display Stack\n4.Exit\n");
        int choice;
        scanf("%d", &choice);
        if(choice==1) Push(&s);
        else if(choice==2) Pop(&s);
        else if(choice==3) Display(s);
        else if(choice==4) break;
        else printf("Enter a Valid Input\n");
        printf("\n");
    }
    
    return 0;
}