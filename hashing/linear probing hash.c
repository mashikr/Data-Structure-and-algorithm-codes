#include <stdio.h>
#define SIZE 10
int H[SIZE];

int hash(int key)
{
    return key%SIZE;
}

int probe(int H[], int key)
{
    int index=hash(key);
    int i=0;
    while(H[(index+i)%SIZE]!=0)
        i++;
    return (index+i)%SIZE;
}

void Insert(int H[], int key)
{
    int index=hash(key);

    if(H[index]!=0)
        index=probe(H,key);

    H[index]=key;
}

int Search(int H[], int key)
{
    int index=hash(key);
    int i=0;

    while(H[(index+i)%SIZE]!=key)
        i++;

    return (index+i)%SIZE;
}

int main()
{
    int H[SIZE]={0};

    Insert(H, 12);
    Insert(H, 25);
    Insert(H, 35);
    Insert(H, 26);

    printf("Key found at: %d\n", Search(H, 35));

    for(int i=0; i<SIZE; i++)
        printf("%d ", H[i]);
    printf("\n");

    return 0;
}
