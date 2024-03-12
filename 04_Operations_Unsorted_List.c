#include <stdio.h>

void PrintArray (int arr[], int n)
{
    printf("Elements of Array are :-\n");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void Insert (int arr[], int * size)
{
    int value;
    printf("Enter the element to be inserted : ");
    scanf("%d", &value);
    int index = *size;
    arr[index] = value;
    (*size)++;
    printf("Element Inserted\n");
    PrintArray(arr, (*size));
}

void Delete (int arr[], int * size)
{
    int value;
    printf("Enter the element to be deleted : ");
    scanf("%d", &value);
    int index = *size;
    int flag = 0;
    int i = 0;
    for (; i < index; i++)
    {
        if(arr[i] == value)
        {
            flag = 1;
            break;
        }
    }
    for (int j = i+1; j < index; j++)
    {
        arr[j-i] = arr[j];
    }
    if(flag) 
    {
        (*size)--;
        printf("Element Deleted\n");
    }
    else printf("Element not Found\n");
    PrintArray(arr, (*size));
}

void Search (int arr[], int size)
{
    int value;
    printf("Enter the element to be Searched : ");
    scanf("%d", &value);
    int flag = 0;
    int found = -1;
    for (int i = 0; i < size; i++)
    {
        if(arr[i] == value)
        {
            found = i;
            flag = 1;
        }
    }
    if(flag) printf("Element is present at index %d\n", found);
    else printf("Element not Found\n");
}

void Update (int arr[], int size)
{
    int x, y;
    printf("Enter the Value to be updated : ");
    scanf("%d", &x);
    printf("Enter its New Value : ");
    scanf("%d", &y);
    int flag = 0;
    for (int i = 0; i < size; i++)
    {
        if(arr[i] == x)
        {
            arr[i] = y;
            flag = 1;
            break;
        }
    }
    if(flag) printf("Element Updated\n");
    else printf("Element not Found\n");
    PrintArray(arr, size);
}

int main(int argc, char const *argv[])
{
    int arr[10000];
    int size = 0;
    while (1)
    {
        printf("\nWhich operation do you want to perform?\n1.Insert\n2.Delete\n3.Search\n4.Update\n5.Display List\n6.Exit\n");
        int choice;
        scanf("%d", &choice);
        if(choice==1) Insert(arr, &size);
        else if(choice==2) Delete(arr, &size);
        else if(choice==3) Search(arr, size);
        else if(choice==4) Update(arr, size);
        else if(choice==5) PrintArray(arr, size);
        else if(choice==6) break;
        else printf("Enter a Valid Input\n");
        printf("\n");
    }
    return 0;
}