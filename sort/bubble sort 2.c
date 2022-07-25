#include <stdio.h>

void swap(int *x, int *y)
{
    int temp=*x;
    *x=*y;
    *y=temp;

}

int * BubbleSort(int A[], int n)
{
    int i,j,flag=0;

    for(i=0; i<n-1; i++)
    {
        flag=0;
        for(j=0; j<n-i-1; j++)
        {
            if(A[j]>A[j+1])
            {
                swap(&A[j], &A[j+1]);
                flag=1;
            }
        }
        if(flag==0) break;
    }
    return A;
}

int main()
{
    int A[]={3,7,9,10,6,5,12,4,11,2};
    int n=10,i;
    int *a;

    a = BubbleSort(A,n);

    for(i=0; i<n; i++)
        printf("%d ", a[i]);

    return 0;
}
