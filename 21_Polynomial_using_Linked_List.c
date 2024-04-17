#include <stdio.h>
#include <stdlib.h>

struct poly
{
    float coeff;
    int expo;
    struct poly* next;
};

struct poly* merge (struct poly* l1, struct poly* l2)
{
    struct poly *t1 = l1, *t2 = l2;
    struct poly* dummy = (struct poly*) malloc (sizeof(struct poly));
    dummy->expo = -1;
    dummy->coeff = -1;
    dummy->next = NULL;
    struct poly* temp = dummy;
    while (t1!=NULL && t2!=NULL)
    {
        if(t1->expo > t2->expo)
        {
            temp->next = t1;
            temp = t1;
            t1 = t1->next;
        }
        else
        {
            temp->next = t2;
            temp = t2;
            t2 = t2->next;
        }
    }
    if(t1) temp->next = t1;
    else temp->next = t2;
    return dummy->next;
}

struct poly* merge_sort (struct poly* s)
{
    if(s == NULL || s->next == NULL) return s;
    struct poly* slow = s;
    struct poly* fast = s->next;
    while (fast != NULL && fast->next != NULL)
    {
        fast = fast->next->next;
        slow = slow->next;
    }
    struct poly* mid = slow;
    struct poly* left = s;
    struct poly* right = mid->next;
    mid->next = NULL;
    struct poly* l = merge_sort(left);
    struct poly* r = merge_sort(right);
    return merge(l, r);
}

void PrintPoly (struct poly* a)
{
    printf("The polynomial is:\n");
    struct poly* q = a;
    if(q != NULL) 
    {
        printf("(%.2fx^%d) ", q->coeff, q->expo);
        q = q->next;
    }
    while (q != NULL)
    {
        printf("+ (%.2fx^%d)", q->coeff, q->expo);
        q = q->next;
    }
    printf("\n");
}

void Insert (struct poly** a, float c, int e)
{
    struct poly *p, *q;
    p = (struct poly*) malloc (sizeof(struct poly));
    p->coeff = c;
    p->expo = e;
    p->next = NULL;

    q = *a;
    if(*a == NULL)
    {
        *a = p;
        return;
    }
    while (q->next != NULL)
    {
        q = q->next;
    }
    q->next = p;
}

void ReadPoly (struct poly **a)
{
    int n;
    printf("No. of terms in polynomial : ");
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        float c; 
        int e;
        printf("Enter coefficient : ");
        scanf("%f", &c);
        printf("Enter exponent : ");
        scanf("%d", &e);
        Insert(a, c, e);
    }
    *a = merge_sort(*a);
    PrintPoly(*a);
}

void AddPoly (struct poly** a, struct poly** b, struct poly** c)
{
    struct poly* t1 = *a;
    struct poly* t2 = *b;
    struct poly* dummy = (struct poly*) malloc (sizeof(struct poly));
    dummy->next = NULL;
    struct poly* temp = dummy;
    while (t1!=NULL && t2!=NULL)
    {
        if(t1->expo == t2->expo)
        {
            struct poly* p = (struct poly*) malloc (sizeof(struct poly));
            p->coeff = t1->coeff + t2->coeff;
            p->expo = t1->expo;
            p->next = NULL;
            temp->next = p;
            temp = p;
            t1 = t1->next;
            t2 = t2->next;
        }
        else if(t1->expo > t2->expo)
        {
            struct poly* p = (struct poly*) malloc (sizeof(struct poly));
            p->coeff = t1->coeff;
            p->expo = t1->expo;
            p->next = NULL;
            temp->next = p;
            temp = p;
            t1 = t1->next;
        }
        else 
        {
            struct poly* p = (struct poly*) malloc (sizeof(struct poly));
            p->coeff = t2->coeff;
            p->expo = t2->expo;
            p->next = NULL;
            temp->next = p;
            temp = p;
            t2 = t2->next;
        }
    }
    if(t1) temp->next = t1;
    else temp->next = t2;
    *c = dummy->next;
}

void MultiTerm (struct poly** b, struct poly** e, float coeff, int expo)
{
    struct poly* start = *b;
    while (start != NULL)
    {
        Insert(e, coeff * start->coeff, expo + start->expo);
        start = start->next;
    }
    *e = merge_sort(*e);
}

void MultiplyPoly (struct poly** a, struct poly** b, struct poly** d)
{
    struct poly *e, *f;
    e = f = NULL;
    struct poly* start = *a;
    while (start != NULL)
    {
        e = NULL;
        MultiTerm(b, &e, start->coeff, start->expo);
        AddPoly(d, &e, &f);
        *d = f;
        start = start->next;
    }
    *d = merge_sort(*d);
}

int main(int argc, char const *argv[])
{
    struct poly *a, *b, *c, *d;
    a = b = c = d = NULL;
    ReadPoly(&a);
    ReadPoly(&b);

    AddPoly(&a, &b, &c);
    PrintPoly(c);

    MultiplyPoly(&a, &b, &d);
    PrintPoly(d);

    return 0;
}
