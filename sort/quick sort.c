#include <stdio.h>

void swap(int *x, int *y)
{
    int temp=*x;
    *x=*y;
    *y=temp;

}

int partition(int A[], int l, int h)
{
    int pivot=A[l];
    int i=l, j=h;

    do
    {
        do{i++;} while(A[i]<=pivot);
        do{j--;} while(A[j]>pivot);

        if(i<j) swap(&A[i], &A[j]);
    } while(i<j);
    swap(&A[l], &A[j]);
    return j;
}

int *QuickSort(int A[], int l, int h)
{
    int j;

    if(l<h)
    {
        j=partition(A,l,h);
        QuickSort(A,l,j);
        QuickSort(A,j+1,h);
    }
    return A;
}

int main()
{
    int A[]={3,7,9,10,6,5,12,4,11,2,65532};
    int n=11,i;
    int *a;

    a = QuickSort(A,0,10);

    for(i=0; i<n; i++)
        printf("%d ", a[i]);

    return 0;
}


