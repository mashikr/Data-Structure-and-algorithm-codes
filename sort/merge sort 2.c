#include<stdio.h>
int arr[20];

int main()
{
  int n,i;

  printf("Enter the size of array\n");
  scanf("%d",&n);
  printf("Enter the elements:");
  for(i=0;i<n;i++)
    scanf("%d",&arr[i]);

  merge_sort(arr,0,n-1);

  printf("Sorted array:");
  for(i=0;i<n;i++)
    printf("%d",arr[i]);

  return 0;
}

int merge_sort(int arr[],int low,int high)
{
  int mid;
  if(low<high)
  {
    mid=(low+high)/2;

    printf("recurtion 1: %d %d\n",low,mid);
    merge_sort(arr,low,mid);

    printf("recurtion 2: %d %d\n",mid+1,high);
    merge_sort(arr,mid+1,high);

    printf("merge: %d %d %d\n",low,mid,high);
    merge(arr,low,mid,high);
  }

  return 0;
}

int merge(int arr[],int l,int m,int h)
{
    printf("merge: %d %d %d\n",l,m,h);
  int arr1[10],arr2[10];
  int n1,n2,i,j,k;
  n1=m-l+1;
  n2=h-m;

  printf("n1 & n2: %d %d\n",n1,n2);

  for(i=0;i<n1;i++)
    arr1[i]=arr[l+i];
  for(j=0;j<n2;j++)
    arr2[j]=arr[m+j+1];

  arr1[i]=9999;
  arr2[j]=9999;

  i=0;j=0;
  for(k=l;k<=h;k++)
  {
    if(arr1[i]<=arr2[j]){
      arr[k]=arr1[i++];
      printf("%d\n",arr1[i]);
    }
    else{
      arr[k]=arr2[j++];
      printf("%d\n",arr1[i]);
    }
  }

  return 0;
}
