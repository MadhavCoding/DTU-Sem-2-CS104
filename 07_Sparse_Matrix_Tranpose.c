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

int main(int argc, char const *argv[])
{
    struct Sparse a[MAXNUM];
    struct Sparse b[MAXNUM];
    ReadSparseMatrix(a);
    TransposeSparseMatrix(a, b);
    PrintSparseMatrix(b);
    return 0;
}