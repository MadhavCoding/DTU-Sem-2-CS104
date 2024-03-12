#include <stdio.h>
#include <string.h>

struct Student
{
    int roll;
    char name[30];
    int marks;
};

void InputArray (struct Student arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("Enter Roll no. : ");
        scanf("%d", &(arr[i].roll));
        printf("Enter Name : ");
        scanf("%s", (arr[i].name));
        printf("Enter Marks : ");
        scanf("%d", &(arr[i].marks));
        printf("\n");
    }
}

void PrintArray (struct Student arr[], int n)
{
    printf("Details of Students are :-\n");
    for (int i = 0; i < n; i++)
    {
        printf("Student %d\n", (i+1));
        printf("Roll no. : %d\n", arr[i].roll);
        printf("Name : %s\n", arr[i].name);
        printf("Marks : %d\n", arr[i].marks);
        printf("\n");
    }
    printf("\n");
}

void swap (struct Student * s1, struct Student * s2)
{
    struct Student temp = *s1;
    *s1 = *s2;
    *s2 = temp;
}

int HoaresPartition (struct Student arr[], int l, int h, int parameter)
{
    switch (parameter)
    {
    case 1:
        char* pivot1 = arr[l].name;
        int i = l-1, j = h+1;
        while (1)
        {
            do
            {
                i++;
            } while (strcmp(arr[i].name,pivot1) < 0);
            do
            {
                j--;
            } while (strcmp(arr[j].name, pivot1) > 0);

            if(j<=i) return j;

            swap(&arr[i], &arr[j]);
        }
        break;
    case 2:
        int pivot = arr[l].marks;
        i = l-1, j = h+1;
        while (1)
        {
            do
            {
                i++;
            } while (arr[i].marks<pivot);
            do
            {
                j--;
            } while (arr[j].marks>pivot);

            if(j<=i) return j;

            swap(&arr[i], &arr[j]);
        }
        break;
    default:
        break;
    }
}

void QSort_H (struct Student arr[], int l, int h, int parameter)
{
    if(l<h)
    {
        int m = HoaresPartition(arr, l, h, parameter);
        QSort_H(arr, l, m, parameter);
        QSort_H(arr, m+1, h, parameter);
    }
}

int main(int argc, char const *argv[])
{
    printf("Enter the no. of Students : ");
    int n; 
    scanf("%d", &n);
    struct Student arr[n];
    InputArray(arr, n);
    PrintArray(arr, n);
    printf("Sorting according to Name\n");
    QSort_H(arr, 0, n-1, 1);
    PrintArray(arr, n);
    printf("Sorting according to Marks\n");
    QSort_H(arr, 0, n-1, 2);
    PrintArray(arr, n);
    return 0;
}