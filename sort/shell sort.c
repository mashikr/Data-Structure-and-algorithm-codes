#include <stdio.h>

int A[20];

void ShellSort(int A[], int n)
{
    int i,j,gap,temp;

    for(gap=n/2; gap>=1; gap/=2)
    {
      for(i=gap; i<n; i++)
      {
          temp=A[i];
          j=i-gap;
          while(j>=0 && A[j]>temp)
          {
              A[j+gap]=A[j];
              j=j-gap;
          }
          A[j+gap]=temp;
      }
    }
}

int main()
{
    int A[]={3,7,9,10,6,5,12,4,11,2};
    int n=10,i;

    ShellSort(A,n);

    for(i=0; i<n; i++)
        printf("%d ", A[i]);

    return 0;
}
