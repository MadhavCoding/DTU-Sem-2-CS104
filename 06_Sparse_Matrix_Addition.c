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

void AddSparseMatrix (struct Sparse a[], struct Sparse b[], struct Sparse c[])
{
    if(a[0].rno == b[0].rno && a[0].cno == b[0].cno)
    {
        c[0].rno = a[0].rno;
        c[0].cno = a[0].cno;
        int t1 = a[0].value;
        int t2 = b[0].value;
        int i=1, j=1, k=1;
        while (i<=t1 && j<=t2)
        {
            if(a[i].rno == b[j].rno && a[i].cno == b[j].cno)
            {
                if(a[i].value + b[j].value != 0)
                {
                    c[k].rno = a[i].rno;
                    c[k].cno = a[i].cno;
                    c[k].value = a[i].value + b[j].value;
                    k++;
                }
                i++; j++;
            }
            else if (a[i].rno < b[j].rno || (a[i].rno == b[j].rno && a[i].cno < b[j].cno))
            {
                c[k].rno = a[i].rno;
                c[k].cno = a[i].cno;
                c[k].value = a[i].value;
                k++; i++;
            }
            else if (a[i].rno > b[j].rno || (a[i].rno == b[j].rno && a[i].cno > b[j].cno))
            {
                c[k].rno = b[j].rno;
                c[k].cno = b[j].cno;
                c[k].value = b[j].value;
                k++; j++;
            }
        }
        
        while (i<=t1)
        {
            c[k].rno = a[i].rno;
            c[k].cno = a[i].cno;
            c[k].value = a[i].value;
            i++; k++;
        }
        while (j<=t2)
        {
            c[k].rno = b[j].rno;
            c[k].cno = b[j].cno;
            c[k].value = b[j].value;
            j++; k++;
        }
        c[0].value = k-1; 
        printf("Result Matrix\n");
        PrintSparseMatrix(c);
    }
    else printf("Matrices can't be added\n");
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
    AddSparseMatrix(a, b, c);
    return 0;
}