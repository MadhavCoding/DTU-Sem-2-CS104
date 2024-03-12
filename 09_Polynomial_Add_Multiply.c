#include <stdio.h>
#define MAXNUM 20

struct poly
{
    float coeff;
    int expo;
};

int sort_helper (struct poly arr[], int l, int h)
{
    int pivot = arr[l].expo;
    int i = l-1, j = h+1;
    while (1)
    {
        do
        {
            i++;
        } while (arr[i].expo>pivot);
        do
        {
            j--;
        } while (arr[j].expo<pivot);

        if(j<=i) return j;

        struct poly temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
    }
}

void sort_poly (struct poly arr[], int l, int h)
{
    if(l<h)
    {
        int m = sort_helper(arr, l, h);
        sort_poly(arr, l, m);
        sort_poly(arr, m+1, h);
    }
}


void print_poly(struct poly a[], int s)
{
    printf("The polynomial is \n");
    for (int i = 0; i < s; i++)
    {
        if(i != 0) printf("+ ");
        printf("(%.2f)x^%d ", a[i].coeff, a[i].expo);
    }
    printf("\n");
}

void read_poly(struct poly a[], int* s)
{
    int n;
    printf("No. of terms in polynomial : ");
    scanf("%d", &n);
    *s = n;
    for (int i = 0; i < n; i++)
    {
        float c; 
        int e;
        printf("Enter coefficient : ");
        scanf("%f", &c);
        printf("Enter exponent : ");
        scanf("%d", &e);
        a[i].coeff = c;
        a[i].expo = e;
    }
    sort_poly(a, 0, n-1);
    print_poly(a, *s);
}

void add_poly(struct poly a[], struct poly b[], struct poly c[], int s1, int s2, int* s3)
{
    int i = 0, j = 0;
    int k = 0;
    while(i < s1 && j < s2)
    {
        if(a[i].expo == b[j].expo)
        {
            c[k].expo = a[i].expo;
            c[k].coeff = a[i].coeff + b[j].coeff;
            i++; j++; k++;
        }
        else if(a[i].expo > b[i].expo)
        {
            c[k].expo = a[i].expo;
            c[k].coeff = a[i].coeff;
            i++; k++;
        }
        else
        {
            c[k].expo = b[j].expo;
            c[k].coeff = b[j].coeff;
            j++; k++;
        }
    }

    while (i < s1)
    {
        c[k].expo = a[i].expo;
        c[k].coeff = a[i].coeff;
        i++; k++;
    }

    while (j < s2)
    {
        c[k].expo = b[j].expo;
        c[k].coeff = b[j].coeff;
        j++; k++;
    }
    
    *s3 = k;
    sort_poly(c, 0, (*s3)-1);
}

void multi_term(struct poly b[], struct poly e[], int s2, struct poly term)
{
    for (int i = 0; i < s2; i++)
    {
        e[i].coeff = term.coeff * b[i].coeff;
        e[i].expo = term.expo + b[i].expo;
    }
    sort_poly(e, 0, s2-1);
}

void multiply_poly(struct poly a[], struct poly b[], struct poly d[], int s1, int s2, int* s4)
{
    struct poly e[MAXNUM]; int s5 = s2;
    struct poly f[MAXNUM]; int s6;
    *s4 = 0;
    for (int i = 0; i < s1; i++)
    {
        multi_term(b, e, s2, a[i]);
        add_poly(d, e, f, *s4, s5, &s6);
        for (int j = 0; j < s6; j++)
        {
            d[j].coeff = f[j].coeff;
            d[j].expo = f[j].expo;
        }
        *s4 = s6;
    }
    
    sort_poly(d, 0, (*s4)-1);
}

int main(int argc, char const *argv[])
{
    struct poly a[MAXNUM]; int s1;
    struct poly b[MAXNUM]; int s2;
    struct poly c[MAXNUM]; int s3;
    struct poly d[MAXNUM]; int s4;
    
    read_poly(a, &s1);
    read_poly(b, &s2);
    add_poly(a, b, c, s1, s2, &s3);
    print_poly(c, s3);
    
    multiply_poly(a, b, d, s1, s2, &s4);
    print_poly(d, s4);
    return 0;
}