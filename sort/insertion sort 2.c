#include <stdio.h>

int * Insertion(int A[], int n)
{
    int i,j,x;

    for(i=1; i<n; i++)
    {
        j=i-1;
        x=A[i];
        while(j>-1 && A[j]>x)
        {
            A[j+1]=A[j];
            j--;
        }
        A[j+1]=x;
    }
    return A;
}

int main()
{
    int A[]={3,7,9,10,6,5,12,4,11,2};
    int n=10,i;
    int *a;

    a = Insertion(A,n);

    for(i=0; i<n; i++)
        printf("%d ", a[i]);

    return 0;
}

