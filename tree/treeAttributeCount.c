#include <stdio.h>
#include <stdlib.h>

struct Node
{
    struct Node *lchild;
    int data;
    struct Node *rchild;
}*root=NULL;

struct Queue
{
    int size;
    int front;
    int rear;
    struct Node **Q;
};

void create (struct Queue *q, int size)
{
    q->size=size;
    q->front=q->rear=0;
    q->Q=(struct Node **)malloc(q->size*sizeof(struct Node *));
}

void enqueue(struct Queue *q, struct Node * x)
{
    if((q->rear+1)%q->size == q->front)
        printf("Queue id full\n");
    else {
        q->rear = (q->rear+1)%q->size;
        q->Q[q->rear] = x;
    }
}

struct Node * dequeue(struct Queue *q)
{
    struct Node * x = NULL;

    if(q->front==q->rear)
        printf("Queue is empty\n");
    else {
        q->front = (q->front+1)%q->size;
        x = q->Q[q->front];
    }
    return x;
}

int isEmpty(struct Queue q)
{
    return q.front == q.rear;
}

void TreeCreate()
{
    struct Node *p,*t;
    int x;
    struct Queue q;
    create(&q,100);

    printf("Enter root value: ");
    scanf("%d", &x);
    root = (struct Node *)malloc(sizeof(struct Node));
    root->data = x;
    root->lchild = root->rchild = NULL;
    enqueue(&q, root);

    while(!isEmpty(q))
    {
        p = dequeue(&q);
        printf("Enter left child of %d: ", p->data);
        scanf("%d", &x);
        if(x != -1)
        {
            t = (struct Node *)malloc(sizeof(struct Node));
            t->data = x;
            t->lchild = t->rchild = NULL;
            p->lchild = t;
            enqueue(&q, t);
        }
        printf("Enter right child of %d: ", p->data);
        scanf("%d", &x);
        if(x != -1)
        {
            t = (struct Node *)malloc(sizeof(struct Node));
            t->data = x;
            t->lchild = t->rchild = NULL;
            p->rchild = t;
            enqueue(&q, t);
        }
    }
}

int count (struct Node *p)
{
    int x,y;
    if (p!=NULL)
    {
        x = count(p->lchild);
        y = count(p->rchild);

        return x+y+1;
    }
    return 0;
}

int height (struct Node *root)
{
    int x=0,y=0;
    if(root==0)
        return 0;
    x = height(root->lchild);
    y = height(root->rchild);

    if(x>y)
        return x+1;
    else
        return y+1;
}

int LeafCount(struct Node *p)
{
    int x,y;

    if(p!=NULL)
    {
        x = LeafCount(p->lchild);
        y = LeafCount(p->rchild);
        if(p->lchild==NULL && p->rchild==NULL)
            return x+y+1;
        else
            return x+y;
    }
    return 0;
}

int main()
{
    TreeCreate();

    printf("Total Node: %d\n", count(root));
    printf("Tree Height: %d\n", height(root));
    printf("Total leaf Node: %d\n", LeafCount(root));

    return 0;
}
