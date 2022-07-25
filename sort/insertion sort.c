#include<stdio.h>
int main()
{
    int arr[8]={3,6,1,4,9,5,3,10};
    int i,j;
    for(i=1;i<8;i++)
    {
        for(j=i-1;j>=0;j--)
        {
           if(arr[i]<arr[j])
           {
               int temp=arr[j];
               arr[j]=arr[i];
               arr[i]=temp;
               i--;
           }
        }
    }
    for(i=0;i<8;i++)
    {
        printf("%d\t",arr[i]);
    }
}
