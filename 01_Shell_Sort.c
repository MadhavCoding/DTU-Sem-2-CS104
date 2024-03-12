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

void ShellSort(int arr[], int n)
{
    for (int gap = n/2; gap > 0; gap=gap/2)
    {
        for (int i = gap; i < n; i++)
        {
            int key = arr[i];
            int j = i-gap;
            while (j>=0 && arr[j]>key)
            {
                arr[j+gap] = arr[j];
                j-=gap;
            }
            arr[j+gap] = key;
        } 
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
    ShellSort(arr, n);
    PrintArray(arr, n);
    return 0;
}