#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node* next;
};

struct headnode
{
    struct node *start, *end;
    int count;
    float avg;
};

struct node* Search (struct headnode* head, int x)
{
    struct node* q = head->start;
    while (q != NULL)
    {
        if(q->data == x) return q;
        q = q->next;
    }
    return NULL;
}

void Insert_at_Beginning (struct headnode* head, int x)
{
    struct node* start = head->start;
    struct node* p = (struct node*) malloc (sizeof(struct node));
    p->data = x;
    p->next = start;
    if(start == NULL) head->end = p;
    head->start = p;
    float sum = head->avg * head->count;
    sum+=x;
    head->count = head->count+1;
    head->avg = sum/head->count;
}

void Insert_at_End (struct headnode* head, int x)
{
    struct node *p, *q;
    p = (struct node*) malloc (sizeof(struct node));
    p->data = x;
    p->next = NULL;
    if(head->end == NULL)
    {
        head->start = p;
        head->end = p;
    }
    else 
    {
        head->end->next = p;
        head->end = p;
    }
    float sum = head->avg * head->count;
    sum+=x;
    head->count = head->count+1;
    head->avg = sum/head->count;
}

void Insert_after (struct headnode* head, int x, int y)
{
    struct node* found = Search(head, y);
    if(found == NULL) Insert_at_End(head, x);
    else
    {
        struct node* p = (struct node*) malloc (sizeof(struct node));
        p->data = x;
        p->next = found->next;
        found->next = p;
        float sum = head->avg * head->count;
        sum+=x;
        head->count = head->count+1;
        head->avg = sum/head->count;
    }
}

void Delete (struct headnode* head, int x)
{
    struct node* start = head->start;
    if(start == NULL) return;
    else if (start->data == x)
    {
        (head->start) = (head->start)->next;
        free(start);
        float sum = head->avg * head->count;
        sum-=x;
        head->count = head->count-1;
        head->avg = sum/head->count;
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
        float sum = head->avg * head->count;
        sum-=x;
        head->count = head->count-1;
        head->avg = sum/head->count;
    }
}

void Display (struct headnode* head)
{
    printf("Elements of the Linked List are:\n");
    struct node* q = head->start;
    while (q != NULL)
    {
        printf("%d ", q->data);
        q = q->next;
    }
    printf("\n");
}

void Insert_at_Beginning1 (struct headnode* head)
{
    int x;
    printf("Enter the Element you want to insert: ");
    scanf("%d", &x);
    Insert_at_Beginning(head, x);
    printf("Element has been inserted\n");
}

void Insert_at_End1 (struct headnode* head)
{
    int x;
    printf("Enter the Element you want to insert: ");
    scanf("%d", &x);
    Insert_at_End(head, x);
    printf("Element has been inserted\n");
}

void Insert_after1 (struct headnode* head)
{
    int x;
    printf("Enter the Element you want to insert: ");
    scanf("%d", &x);
    int y;
    printf("Enter the Element after which you want to insert: ");
    scanf("%d", &y);
    Insert_after(head, x, y);
    printf("Element has been inserted\n");
}

void Delete1 (struct headnode* head)
{
    if((head->start) == NULL) 
    {
        printf("Linked List is Empty\n");
        return;
    }
    int x;
    printf("Enter the Element you want to delete: ");
    scanf("%d", &x);
    Delete(head, x);
    printf("Element has been deleted\n");
}

void Search1 (struct headnode* head)
{
    int x;
    printf("Enter the Element you want to search: ");
    scanf("%d", &x);
    struct node* found = Search(head, x);
    if(found == NULL) printf("Element is not found\n");
    else printf("Element has been found\n");
}

void printNodes (struct headnode* head)
{
    printf("The no. of nodes in the Linked List are: %d\n", head->count);
}

void printAverage (struct headnode* head)
{
    printf("The average of nodes in the Linked List are: %.2f\n", head->avg);
}

int main(int argc, char const *argv[])
{
    struct headnode* head = (struct headnode*) malloc (sizeof(struct headnode));
    head->start = NULL; head->end = NULL; head->count = 0; head->avg = 0;
    while (1)
    {
        printf("\nWhich operation do you want to perform?\n1.Insert at Beginning\n2.Insert at End\n3.Insert after y\n4.Delete\n5.Search\n6.Display\n7.No. of Nodes\n8.Average of Nodes\n9.Exit\n");
        int choice;
        scanf("%d", &choice);
        if(choice==1) Insert_at_Beginning1(head);
        else if(choice==2) Insert_at_End1(head);
        else if(choice==3) Insert_after1(head);
        else if(choice==4) Delete1(head);
        else if(choice==5) Search1(head);
        else if(choice==6) Display(head);
        else if(choice==7) printNodes(head);
        else if(choice==8) printAverage(head);
        else if(choice==9) break;
        else printf("Enter a Valid Input\n");
        printf("\n");
    }
    return 0;
}