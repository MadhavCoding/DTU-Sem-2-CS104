#include <stdio.h>
#define MAXNUM 20

struct Sparse
{
    int rno;
    int cno;
    int value;
};

void PrintSparseMatrix (struct Sparse s[])
{
    printf("\nThe elements of the Matrix are : \n");
    int row = s[0].rno;
    int col = s[0].cno;
    int t = s[0].value;
    int k = 1;
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            if(s[k].rno == i && s[k].cno == j)
            {
                printf("%d ", s[k].value);
                k++;
            }
            else
            {
                printf("%d ", 0);
            }
        }
        printf("\n");
    } 
    printf("\n"); 
}

void ReadSparseMatrix(struct Sparse s[])
{
    printf("No. of rows : ");
    int rows;
    scanf("%d", &rows);
    printf("No. of columns : ");
    int cols;
    scanf("%d", &cols);
    s[0].rno = rows;
    s[0].cno = cols;
    int count = 0;
    int k = 1;
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            printf("Enter the element : ");
            int element;
            scanf("%d", &element);
            if(element != 0)
            {
                s[k].rno = i;
                s[k].cno = j;
                s[k].value = element;
                count++;
                k++;
            }
        }
        printf("\n");
    }
    s[0].value = count;
    PrintSparseMatrix(s);
}

void TransposeSparseMatrix (struct Sparse s[], struct Sparse t[])
{
    t[0].rno = s[0].cno;
    t[0].cno = s[0].rno;
    t[0].value = s[0].value;
    int c[s[0].cno];
    for (int i = 0; i < s[0].cno; i++)
    {
        c[i] = 0;
    }
    for (int i = 1; i <= s[0].value; i++)
    {
        c[s[i].cno]++;
    }
    int m[s[0].cno];
    m[0] = 1;
    for (int i = 1; i < s[0].cno; i++)
    {
        m[i] = m[i-1] + c[i-1];
    }
    for (int i = 1; i <= s[0].value; i++)
    {
        int j = m[s[i].cno];
        t[j].rno = s[i].cno;
        t[j].cno = s[i].rno;
        t[j].value = s[i].value;
        m[s[i].cno]++;
    }
}

void MultiplyHelper (struct Sparse a[], struct Sparse t[], struct Sparse c[], int row, int* ptr, int* i1)
{
    int numbers[t[0].rno];
    for (int i = 0; i < t[0].rno; i++)
    {
        numbers[i] = 0;
    }
    int i = *i1;
    while (i <= a[0].value && a[i].rno == row)
    {
        int j = 1;
        while (j <= t[0].value)
        {
            if(a[i].rno == row && a[i].cno == t[j].cno) numbers[t[j].rno] += (a[i].value * t[j].value);
            j++;
        }
        i++;
    }
    *i1 = i;
    int index = *ptr;
    for (int i = 0; i < t[0].rno; i++)
    {
        if(numbers[i])
        {
            c[index].rno = row;
            c[index].cno = i;
            c[index].value = numbers[i];
            index++;
        }
    }
    *ptr = index;
}

void MultiplySparseMatrix (struct Sparse a[], struct Sparse b[], struct Sparse c[])
{
    if(a[0].cno == b[0].rno)
    {
        struct Sparse t[MAXNUM];
        TransposeSparseMatrix(b, t);
        c[0].rno = a[0].rno; 
        c[0].cno = t[0].rno;
        int k = 1; int i1 = 1;
        for (int i = 0; i < a[0].rno; i++)
        {
            MultiplyHelper(a, t, c, i, &k, &i1); 
        }
        c[0].value = k-1; 
        printf("Result Matrix\n");
        PrintSparseMatrix(c);
    }
    else 
    {
        printf("Matrices can't be multiplied\n");
    }
}

int main(int argc, char const *argv[])
{
    struct Sparse a[MAXNUM];
    struct Sparse b[MAXNUM];
    struct Sparse c[MAXNUM];
    printf("First Matrix\n");
    ReadSparseMatrix(a);
    printf("Second Matrix\n");
    ReadSparseMatrix(b);
    MultiplySparseMatrix(a, b, c);
    return 0;
}