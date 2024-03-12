// Program 2 : Quick Sort
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

int LomutoPartition (int arr[], int l, int h)
{
    int pivot = arr[h];
    int index = -1;
    for (int i = 0; i <= h-1; i++)
    {
        if(arr[i]<=pivot)
        {
            index++;
            int temp = arr[index];
            arr[index] = arr[i];
            arr[i] = temp;
        }
    }
    arr[h] = arr[index+1];
    arr[index+1] = pivot;
    return index+1;
}

int HoaresPartition (int arr[], int l, int h)
{
    int pivot = arr[l];
    int i = l-1, j = h+1;
    while (1)
    {
        do
        {
            i++;
        } while (arr[i]<pivot);
        do
        {
            j--;
        } while (arr[j]>pivot);

        if(j<=i) return j;

        int temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
    }
}

void QSort_L (int arr[], int l, int h)
{
    if(l<h)
    {
        int m = LomutoPartition(arr, l, h);
        QSort_L(arr, l, m-1);
        QSort_L(arr, m+1, h);
    }
}

void QSort_H (int arr[], int l, int h)
{
    if(l<h)
    {
        int m = HoaresPartition(arr, l, h);
        QSort_H(arr, l, m);
        QSort_H(arr, m+1, h);
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
    QSort_L(arr, 0, n-1);
    PrintArray(arr, n);
    QSort_H(arr, 0, n-1);
    PrintArray(arr, n);
    return 0;
}