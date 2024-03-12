#include <stdio.h>

void InputArray (int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("Enter an element : ");
        scanf("%d", arr+i);
    }
}

void PrintArray (int arr[], int n)
{
    printf("Elements of Array are :-\n");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void swap (int arr[], int i, int j)
{
    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}

void Heapify (int a[], int n, int i)
{
    int li = i;
    int left = 2*i + 1;
    int right = 2*i + 2;
    if(left < n && a[left] > a[li]) li = left;
    if(right < n && a[right] > a[li]) li = right;
    if(li != i)
    {
        swap(a, i, li);
        Heapify(a, n, li);
    }
}

void MakeHeap (int a[], int n)
{
    for (int i = n/2 - 1; i >= 0; i--)
    {
        Heapify(a, n, i);
    }
}

void DeleteMax (int a[], int n)
{
    swap(a, n-1, 0);
    Heapify(a, n-1, 0);
}

void HeapSort (int a[], int n)
{
    MakeHeap(a, n);
    for (int i = n; i > 1; i--)
    {
        DeleteMax(a, i);
    }
}

int main(int argc, char const *argv[])
{
    printf("Enter size of array : ");
    int n;
    scanf("%d", &n);
    int arr[n];
    InputArray(arr, n);
    PrintArray(arr, n);
    printf("After Sorting\n");
    HeapSort(arr, n);
    PrintArray(arr, n);
    return 0;
}