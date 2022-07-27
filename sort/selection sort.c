#include <stdio.h>

void swap(int *x, int *y)
{
    int temp=*x;
    *x=*y;
    *y=temp;

}

int * SelectionSort(int A[], int n)
{
    int i,j,k;

    for(i=0; i<n-1; i++)
    {
        for(j=k=i; j<n; j++)
        {
            if(A[j]<A[k])
                k=j;
        }
        swap(&A[i], &A[k]);
    }
    return A;
}

int main()
{
    int A[]={3,7,9,10,6,5,12,4,11,2};
    int n=10,i;
    int *a;

    a = SelectionSort(A,n);

    for(i=0; i<n; i++)
        printf("%d ", a[i]);

    return 0;
}

