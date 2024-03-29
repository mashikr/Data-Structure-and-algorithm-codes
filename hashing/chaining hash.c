#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

void SortedInsert(struct Node **H, int x)
{
    struct Node *t, *q = NULL, *p=*H;

    t = (struct Node *)malloc(sizeof(struct Node));
    t->data = x;
    t->next = NULL;

    if (*H == NULL)
        *H = t;
    else
    {
        while(p && p->data < x)
        {
            q = p;
            p = p->next;
        }
        if (p == *H)
        {
            t->next = *H;
            *H = t;
        } else
        {
            t->next = q->next;
            q->next = t;
        }
    }
}

struct Node * Search(struct Node *p, int key)
{
    while(p != NULL)
    {
        if(key == p->data)
            return p;
        p = p->next;
    }
    return NULL;
}

int hash(int key, int size)
{
    return key%size;
}

void Insert(struct Node *H[],int size, int key)
{
    int index = hash(key, size);
    SortedInsert(&H[index], key);
}

int main()
{
    int size=10,i;
    struct Node *HT[size], *temp;

    for(i=0; i<size; i++)
        HT[i]=NULL;

    Insert(HT,size,22);
    Insert(HT,size,42);
    Insert(HT,size,12);


    temp=Search(HT[hash(22,size)], 22);

    printf("%d ", temp->data);


    return 0;
}
