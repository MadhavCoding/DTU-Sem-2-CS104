#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node* next;
};

struct Stack
{
    struct node* top;
};

void initialise (struct Stack * stk)
{
    stk->top = NULL;
}

int isEmpty (struct Stack stk)
{
    if (stk.top == NULL) return 1;
    return 0;
}

void Push (struct Stack* stk, int x)
{
    struct node* p = (struct node*) malloc (sizeof(struct node));
    p->data = x;
    p->next = stk->top;
    stk->top = p;
}

void Pop (struct Stack* stk)
{
    if(isEmpty(*stk)) return;
    struct node* p = stk->top;
    stk->top = stk->top->next;
    free(p);
}

void Display (struct Stack* stk)
{
    printf("Elements of the Stack are:\n");
    struct node* q = stk->top;
    while (q != NULL)
    {
        printf("%d ", q->data);
        q = q->next;
    }
    printf("\n");
}

void Push1 (struct Stack* stk)
{
    int x;
    printf("Enter the Element you want to push: ");
    scanf("%d", &x);
    Push(stk, x);
    printf("Element has been pushed\n");
}

void Pop1 (struct Stack* stk)
{
    if(isEmpty(*stk)) 
    {
        printf("Stack is Empty\n");
        return;
    }
    Pop(stk);
    printf("Element has been popped\n");
}

int main(int argc, char const *argv[])
{
    struct Stack stk;
    initialise(&stk);
    while (1)
    {
        printf("\nWhich operation do you want to perform?\n1.Push\n2.Pop\n3.Display Stack\n4.Exit\n");
        int choice;
        scanf("%d", &choice);
        if(choice==1) Push1(&stk);
        else if(choice==2) Pop1(&stk);
        else if(choice==3) Display(&stk);
        else if(choice==4) break;
        else printf("Enter a Valid Input\n");
        printf("\n");
    }
    
    return 0;
}