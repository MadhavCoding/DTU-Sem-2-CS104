#include <stdio.h>
#define MAXNUM 20

struct Priority_Queue
{
    int arr[MAXNUM];
    int size;
};

void swap (int arr[], int i, int j)
{
    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}

void initialise(struct Priority_Queue* pq)
{
    pq->size = 0;
}

int isFull (struct Priority_Queue pq)
{
    if (pq.size == MAXNUM) return 1;
    return 0;
}

int isEmpty (struct Priority_Queue pq)
{
    if (pq.size == 0) return 1;
    return 0;
}

void Insert (struct Priority_Queue* pq)
{
    if(isFull(*pq))
    {
        printf("Queue is Full\n");
        return;
    }
    int x;
    printf("Enter the element to be inserted : ");
    scanf("%d", &x);
    int n = pq->size;
    pq->arr[n] = x;
    n = n+1;
    pq->size = n;
    int i = n-1;
    int parent_index = (i-1)/2;
    while (parent_index >= 0 && pq->arr[parent_index] < pq->arr[i])
    {
        swap(pq->arr, parent_index, i);
        i = parent_index;
        parent_index = (i-1)/2;
    }
    printf("%d is inserted\n", x);
}

int Delete (struct Priority_Queue* pq)
{
    if (isEmpty(*pq))
    {
        printf("Queue is Empty\n");
        return -1;
    }
    
    int x = pq->arr[0];
    pq->arr[0] = pq->arr[(pq->size) - 1];
    pq->size = pq->size - 1;
    int i = 0;
    do
    {
        int left = 2*i + 1;
        int right = 2*i + 2;
        int li = i;
        if(left < pq->size && pq->arr[left] > pq->arr[li]) li = left;
        if(right < pq->size && pq->arr[right] > pq->arr[li]) li = right;
        if(li != i)
        {
            swap(pq->arr, i, li);
            i = li;
        }
        else break;
    } while (1);
    printf("%d is deleted\n", x);
   return x; 
}

int main(int argc, char const *argv[])
{
    struct Priority_Queue pq;
    initialise(&pq);
    while (1)
    {
        printf("\nWhich operation do you want to perform?\n1.Insert\n2.Delete_Max\n3.Exit\n");
        int choice;
        scanf("%d", &choice);
        if(choice==1) Insert(&pq);
        else if(choice==2) Delete(&pq);
        else if(choice==3) break;
        else printf("Enter a Valid Input\n");
        printf("\n");
    }
    
    return 0;
}