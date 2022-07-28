#include <stdio.h>
#include <limits.h>
#include <stdlib.h>

int A[20];

int findMax(int A[], int n)
{
    int max=INT_MIN;
    int i;
    for(i=0; i<n; i++)
    {
        if(A[i]>max)
            max=A[i];
    }
    return max;
}

void CountSort(int A[], int n)
{
    int i,j,max,*C;
    max = findMax(A, n);

    C=(int *)malloc(sizeof(int)*(max+1));

    for(i=0; i<max+1; i++)
        C[i]=0;

    for(i=0; i<n; i++)
        C[A[i]]++;

    i=0;j=0;
    while(j<max+1)
    {
        if(C[j]>0)
        {
            A[i++ ]=j;
            C[j]--;
        } else
            j++;
    }
}


int main()
{
    int A[]={3,7,9,10,6,5,12,4,11,2};
    int n=10,i;

    CountSort(A,n);

    for(i=0; i<n; i++)
        printf("%d ", A[i]);

    return 0;
}
