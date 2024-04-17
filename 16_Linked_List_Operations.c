#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node* next;
};

struct node* Search (struct node* start, int x)
{
    struct node* q = start;
    while (q != NULL)
    {
        if(q->data == x) return q;
        q = q->next;
    }
    return NULL;
}

void Insert_at_Beginning (struct node** s, int x)
{
    struct node* start = *s;
    struct node* p = (struct node*) malloc (sizeof(struct node));
    p->data = x;
    p->next = start;
    *s = p;
}

void Insert_at_End (struct node** s, int x)
{
    struct node *p, *q;
    p = (struct node*) malloc (sizeof(struct node));
    p->data = x;
    p->next = NULL;
    q = *s;
    if(*s == NULL)
    {
        *s = p;
        return;
    }
    while (q->next != NULL)
    {
        q = q->next;
    }
    q->next = p;
}

void Insert_after (struct node** s, int x, int y)
{
    struct node* found = Search(*s, y);
    if(found == NULL) Insert_at_End(s, x);
    else
    {
        struct node* p = (struct node*) malloc (sizeof(struct node));
        p->data = x;
        p->next = found->next;
        found->next = p;
    }
}

void Delete (struct node** s, int x)
{
    struct node* start = *s;
    if(start == NULL) return;
    else if (start->data == x)
    {
        (*s) = (*s)->next;
        free(start);
        return;
    }
    while (start->next != NULL && (start->next)->data != x)
    {
        start = start->next;
    }
    if(start->next != NULL)
    {
        struct node* p = start->next;
        start->next = start->next->next;
        free(p);
    }
}

void Display (struct node* start)
{
    printf("Elements of the Linked List are:\n");
    struct node* q = start;
    while (q != NULL)
    {
        printf("%d ", q->data);
        q = q->next;
    }
    printf("\n");
}

void Insert_at_Beginning1 (struct node** s)
{
    int x;
    printf("Enter the Element you want to insert: ");
    scanf("%d", &x);
    Insert_at_Beginning(s, x);
    printf("Element has been inserted\n");
}

void Insert_at_End1 (struct node** s)
{
    int x;
    printf("Enter the Element you want to insert: ");
    scanf("%d", &x);
    Insert_at_End(s, x);
    printf("Element has been inserted\n");
}

void Insert_after1 (struct node** s)
{
    int x;
    printf("Enter the Element you want to insert: ");
    scanf("%d", &x);
    int y;
    printf("Enter the Element after which you want to insert: ");
    scanf("%d", &y);
    Insert_after(s, x, y);
    printf("Element has been inserted\n");
}

void Delete1 (struct node** s)
{
    if((*s) == NULL) 
    {
        printf("Linked List is Empty\n");
        return;
    }
    int x;
    printf("Enter the Element you want to delete: ");
    scanf("%d", &x);
    Delete(s, x);
    printf("Element has been deleted\n");
}

void Search1 (struct node** s)
{
    int x;
    printf("Enter the Element you want to search: ");
    scanf("%d", &x);
    struct node* found = Search(*s, x);
    if(found == NULL) printf("Element is not found\n");
    else printf("Element has been found\n");
}

int main(int argc, char const *argv[])
{
    struct node* start = (struct node*) malloc (sizeof(struct node));
    start = NULL;
    while (1)
    {
        printf("\nWhich operation do you want to perform?\n1.Insert at Beginning\n2.Insert at End\n3.Insert after y\n4.Delete\n5.Search\n6.Display\n7.Exit\n");
        int choice;
        scanf("%d", &choice);
        if(choice==1) Insert_at_Beginning1(&start);
        else if(choice==2) Insert_at_End1(&start);
        else if(choice==3) Insert_after1(&start);
        else if(choice==4) Delete1(&start);
        else if(choice==5) Search1(&start);
        else if(choice==6) Display(start);
        else if(choice==7) break;
        else printf("Enter a Valid Input\n");
        printf("\n");
    }
    return 0;
}