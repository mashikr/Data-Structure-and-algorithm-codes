#include <stdio.h>

void Insert(int *H[], int n)
{
    int i=n,temp;
    temp=H[i];

    while(i>1 && temp>H[i/2])
    {
       H[i] = H[i/2];
       i = i/2;
    }
    H[i] = temp;
}

int Delete(int H[], int n)
{
    int i,j,x,val,temp;
    val=H[1];
    x=H[n];
    H[1]=H[n];
    H[n]=val;
    i=1;
    j=i*2;

    while(j<n-1)
    {
        if(H[j+1]>H[j])
            j=j+1;
        if(H[i]<H[j])
        {
            temp=H[i];
            H[i]=H[j];
            H[j]=temp;
            i=j;
            j=2*j;
        } else
            break;
    }
    return val;
}

int main()
{
    int H[]={0,2,5,8,9,4,10,7};

    for(int i=0; i<=7; i++)
        Insert(H, i);

    for(int i=7; i>1; i--)
    {
        printf("%d ", Delete(H, i));
    }
    //printf("Deleted value: %d\n", Delete(H, 7));
    //for(int i=0; i<=7; i++)
     //   printf("%d  ", H[i]);

    return 0;
}
