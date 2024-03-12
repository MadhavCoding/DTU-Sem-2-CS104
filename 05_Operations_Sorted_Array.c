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

int SearchHelp (int arr[], int size, int value)
{
    int low = 0; int high = size-1;
    while (high>=low)
    {
        int mid = (low+high)/2;
        if(arr[mid] == value) return mid;
        else if(arr[mid] > value) high = mid-1;
        else low = mid+1;
    }
    return -1;
}

int CeilValue (int arr[], int size, int value)
{
    if(size==0) return 0;
    else if(value>arr[size-1]) return size;
    int low = 0; int high = size-1;
    while (low<high)
    {
        int mid = (low+high)/2;
        if(arr[mid]>=value) high = mid;
        else low = mid+1;
    }
    return high;
}

void InsertHelp (int arr[], int size, int value)
{
    int resultIndex = CeilValue(arr, size, value);
    for (int i = size-1; i >= resultIndex; i--)
    {
        arr[i+1] = arr[i];
    }
    arr[resultIndex] = value;
}

int DeleteHelp (int arr[], int size, int value)
{
    int flag = 0;
    int i = SearchHelp(arr, size, value);
    if(i!=-1)
    {
        flag = 1;
        for (int j = i+1; j < size; j++)
        {
            arr[j-1] = arr[j];
        }
    }
    return flag;
}

void Insert (int arr[], int * size)
{
    int value;
    printf("Enter the element to be inserted : ");
    scanf("%d", &value);
    int index = *size;
    InsertHelp(arr, index, value);
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
    int flag = DeleteHelp(arr, index, value);
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
    int found = SearchHelp(arr, size, value);
    if(found != -1) printf("Element is present at index %d\n", found);
    else printf("Element not Found\n");
}

void Update (int arr[], int size)
{
    int x, y;
    printf("Enter the Value to be updated : ");
    scanf("%d", &x);
    printf("Enter its New Value : ");
    scanf("%d", &y);
    int flag = DeleteHelp(arr, size, x);;
    if(flag) 
    {
        InsertHelp(arr, size, y);
        printf("Element Updated\n");
    }
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