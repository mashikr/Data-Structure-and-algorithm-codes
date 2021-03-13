#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <stdbool.h>

struct Node
{
    int data;
    struct Node *next;
}*first=NULL, *second=NULL, *third=NULL;

void create(int A[], int n)
{
    int i;
    struct Node *t, *last;
    first = (struct Node *)malloc(sizeof(struct Node));
    first->data = A[0];
    first->next = NULL;
    last = first;

    for(i=1; i<n; i++)
    {
        t = (struct Node *)malloc(sizeof(struct Node));
        t->data = A[i];
        t->next = NULL;
        last->next = t;
        last = t;
    }
}

void create2(int A[], int n)
{
    int i;
    struct Node *t, *last;
    second = (struct Node *)malloc(sizeof(struct Node));
    second->data = A[0];
    second->next = NULL;
    last = second;

    for(i=1; i<n; i++)
    {
        t = (struct Node *)malloc(sizeof(struct Node));
        t->data = A[i];
        t->next = NULL;
        last->next = t;
        last = t;
    }
}

void Display(struct Node *p)
{
    while(p != 0)
    {
        printf("%d ", p->data);
        p = p->next;
    }
    printf("\n");
}

void ReverseDisplay(struct Node *p)
{
    if (p != NULL)
    {
        ReverseDisplay(p->next);
        printf("%d ", p->data);
    }
}

int Count(struct Node *p)
{
    int count = 0;
    while(p != 0)
    {
        count++;
        p = p->next;
    }

    return count;
}

int Sum(struct Node *p)
{
    int sum = 0;
    while(p != 0)
    {
        sum += p->data;
        p = p->next;
    }

    return sum;
}
int Max(struct Node *p)
{
    int max = INT_MIN;

    while(p)
    {
        if(p->data>max)
            max = p->data;
        p = p->next;
    }
    return max;
}

struct Node * LSearch(struct Node *p, int key)
{
    while(p != NULL)
    {
        if(key == p->data)
            return p;
        p = p->next;
    }
    return NULL;
}

void Insert (struct Node *p, int index, int x)
{
    struct Node *t;

    if(index < 0 || index > Count(p))
        return;
    t = (struct Node *)malloc(sizeof(struct Node));
    t->data = x;

    if (index == 0)
    {
        t->next = first;
        first = t;
    } else
    {
        for(int i=1; i<index-1; i++)
        {
            p = p->next;
        }
        t->next = p->next;
        p->next = t;
    }
}

void SortedInsert(struct Node *p, int x)
{
    struct Node *t, *q = NULL;

    t = (struct Node *)malloc(sizeof(struct Node));
    t->data = x;
    t->next = NULL;

    if (first == NULL)
        first = t;
    else
    {
        while(p && p->data < x)
        {
            q = p;
            p = p->next;
        }
        if (p == first)
        {
            t->next = first;
            first = t;
        } else
        {
            t->next = q->next;
            q->next = t;
        }
    }
}

int Delete(struct Node *p, int index)
{
    struct Node *q = NULL;
    int x = -1, i;

    if(index < 1 || index > Count(p))
        return -1;
    if(index == 1)
    {
        q = first;
        x = first->data;
        first = first->next;
        free(q);
        return x;
    } else
    {
       for(i=1; i<index; i++)
       {
           q = p;
           //printf("%d\n", p->data);
           p = p->next;
       }
       q->next = p->next;
       x = p->data;
       free(p);
       return x;
    }
}

bool isSorted(struct Node *p)
{
    int x = -65536;

    while(p != NULL)
    {
        if(p->data < x)
            return false;
        x = p->data;
        p = p->next;
    }
    return true;
}

void RemoveDuplicate(struct Node *p)
{
    struct Node *q = p->next;

    while(q != NULL)
    {
        if(p->data != q->data)
        {
            p = q;
            q = q->next;
        } else
        {
           p->next = q->next;
           free(q);
           q = p->next;
        }
    }
}

void ReverseByArray(struct Node *p)
{
    int *A, i=0;
    struct Node *q = p;

    A = (int *)malloc(sizeof(int) * Count(p));

    while(q != NULL)
    {
        A[i] = q->data;
        q = q->next;
        i++;
    }
    q = p;
    i--;

    while(q != NULL)
    {
        q->data = A[i];
        q = q->next;
        i--;
    }
}

void ReverseByPointer(struct Node *p)
{
    struct Node *q = NULL, *r = NULL;

    while(p != 0)
    {
        r = q;
        q = p;
        p = p->next;
        q->next = r;
    }
    first = q;
}

void ReverseByRecursion(struct Node *q, struct Node *p)
{
    if (p)
    {
        ReverseByRecursion(p, p->next);
        p->next = q;
    } else
        first = q;
}

void Concat(struct Node *p, struct Node *q)
{
    third = p;

    while(p->next != NULL)
        p = p->next;
    p->next = q;
}

void Merge(struct Node *p, struct Node *q)
{
    struct Node *last;
    if(p->data < q->data)
    {
        third = last = p;
        p = p->next;
        third->next = NULL;
    } else
    {
        third = last = q;
        q = q->next;
        third->next = NULL;
    }

    while(p && q)
    {
        if(p->data < q->data)
        {
            last->next = p;
            last = p;
            p = p->next;
            last->next = NULL;
        } else
        {
            last->next = q;
            last = q;
            q = q->next;
            last->next = NULL;
        }
    }

    if(p) last->next = p;
    if(q) last->next = q;
}

int isLoop(struct Node *f)
{
    struct Node *p, *q;
    p = q = f;

    do
    {
        p = p->next;
        q = q->next;
        q = q ? q->next : q;
    } while (p && q && p != q);

    if(p == q)
        return 1;
    else
        return 0;
}

int main ()
{
    // int A[] = {3, 5, 7, 10, 15};
    // int B[] = {2, 4, 6, 11};
    // create(A, 5);
    // create2(B, 4);

    //Insert(first, 5, 8);
    //SortedInsert(first, 16);

    // printf("Deleted item: %d\n", Delete(first, 3));
    // printf("IsSorted: %d\n", isSorted(first));
    // RemoveDuplicate(first);

    // ReverseByArray(first);
    // ReverseByPointer(first);
    // ReverseByRecursion(0, first);

    // Concat(first, second);
    // Merge(first, second);
    // printf("Concatinated: ");
    // Display(third);

    //Display(first);
    //Display(second);

    // ReverseDisplay(first);
    // printf("Total node: %d\n", Count(first));
    // printf("Total value: %d\n", Sum(first));
    // printf("Max value: %d\n", Max(first));

    /*
    struct Node * temp = LSearch(first, 1);
    if (temp)
        printf("Key is Found %d\n", temp->data);
    else
        printf("Key not found\n");
    */

    struct Node *t1, *t2;
    int A[] = {10, 20, 30, 40, 50};
    create(A, 5);

    // t1 = first->next->next;
    // t2 = first->next->next->next->next;
    // t2->next = t1;

    printf("Is loop: %d\n", isLoop(first));

    return 0;
}
