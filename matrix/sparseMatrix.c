#include <stdio.h>
#include <stdlib.h>

struct Element
{
    int i;
    int j;
    int x;
};

struct Sparse
{
    int m;
    int n;
    int num;
    struct Element *el;
};

void create (struct Sparse *s)
{
    int i;
    printf("Enter Dimensions: ");
    scanf("%d%d", &s->m, &s->n);
    printf("Number of non-zero: ");
    scanf("%d", &s->num);

    s->el = (struct Element *)malloc(s->num * sizeof(struct Element));

    for(i=0; i<s->num; i++)
        scanf("%d%d%d", &s->el[i].i, &s->el[i].j, &s->el[i].x);
}

void display (struct Sparse s)
{
    int i,j,k=0;

    for (i=0; i<s.m; i++)
    {
        for (j=0; j<s.n; j++)
        {
            if (i==s.el[k].i && j==s.el[k].j)
                printf("%d ", s.el[k++].x);
            else
                printf("0 ");
        }
        printf("\n");
    }
}

struct Sparse * add (struct Sparse *s1, struct Sparse *s2)
{
    struct Sparse *sum;
    int i,j,k;
    i=j=k=0;

    if (s1->m != s2->m || s1->n != s2->n)
        return 0;

    sum = (struct Sparse *)malloc(sizeof(struct Sparse));
    sum->el = (struct Element *)malloc((s1->num+s2->num)*sizeof(struct Element));

    while(i<s1->num && j<s2->num)
    {
        if(s1->el[i].i < s2->el[j].i)
            sum->el[k++] = s1->el[i++];
        else if (s1->el[i].i > s2->el[j].i)
            sum->el[k++] = s2->el[j++];
        else
        {
            if(s1->el[i].j < s2->el[j].j)
                sum->el[k++] = s1->el[i++];
            else if(s1->el[i].j > s2->el[j].j)
                sum->el[k++] = s2->el[j++];
            else
            {
                sum->el[k] = s1->el[i];
                sum->el[k++].x = s1->el[i++].x + s2->el[j++].x;
            }
        }
    }

    for(; i<s1->num; i++) sum->el[k++] = s1->el[i];
    for(; j<s2->num; j++) sum->el[k++] = s2->el[j];
    sum->num = k;
    sum->m = s1->m;
    sum->n = s1->n;

    return sum;
}

int main ()
{
    struct Sparse s1, s2, *s3;

    create(&s1);
    create(&s2);

    s3 = add(&s1, &s2);

    printf("First Matrix:\n");
    display(s1);
    printf("Second Matrix:\n");
    display(s2);
    printf("Sum Matrix:\n");
    display(*s3);
    return 0;
}

/*
4 5
4
0 0 5
0 4 5
1 2 5
3 3 5

4 5
3
0 4 3
1 3 3
2 3 3
*/
