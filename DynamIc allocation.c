#include<stdio.h>
#include<stdlib.h>
int main()
{
    int *ptr;
     ptr = (int *) malloc(5 * sizeof(int));

     ptr[1] = 5;
     ptr[3] = 50;

     printf("%d\n",ptr[1]);
     printf("%d\n",ptr[3]);
}

