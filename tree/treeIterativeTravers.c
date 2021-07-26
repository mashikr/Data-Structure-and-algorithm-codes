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

struct Stack
{
    int size;
    int top;
    struct Node **S;
};

// Start Queue part
void create(struct Queue *q, int size)
{
    q->size = size;
    q->front = q->rear = 0;
    q->Q = (struct Node **)malloc(q->size*sizeof(struct Node *));
}

void enqueue(struct Queue *q, struct Node *x)
{
    if((q->rear+1)%q->size == q->front)
        printf("Queue is full\n");
    else
    {
        q->rear = (q->rear+1)%q->size;
        q->Q[q->rear] = x;
    }
}

struct Node * dequeue(struct Queue *q)
{
    struct Node *x = NULL;

    if(q->front == q->rear)
        printf("Queue is empty\n");
    else
    {
        q->front = (q->front+1)%q->size;
        x = q->Q[q->front];
    }

    return x;
}

int isEmpty(struct Queue q)
{
    return q.front == q.rear;
}
// End Queue part

// Start Stack part
void Stackcreate(struct Stack *st, int size)
{
    st->size = size;
    st->top = -1;
    st->S = (struct Node **)malloc(st->size*sizeof(struct Node *));
}

void push(struct Stack *st, struct Node *x)
{
    if(st->top == st->size-1)
        printf("Stack Overflow\n");
    else
    {
        st->top++;
        st->S[st->top] = x;
    }
}

struct Node * pop(struct Stack *st)
{
    struct Node *x = NULL;
    if(st->top==-1)
        printf("Stack Underflow\n");
    else
    {
        x = st->S[st->top--];
    }
    return x;
}

int isEmptyStack(struct Stack st)
{
    if(st.top==-1)
        return 1;
    return 0;
}

int isFullStack(struct Stack st)
{
    return st.top == st.size-1;
}

struct Node* peek(struct Stack stack)
{
    if (isEmptyStack(stack))
        return NULL;
    return stack.S[stack.top];
}
// End Stack part

void TreeCreate()
{
    struct Node *p, *t;
    int x;
    struct Queue q;
    create(&q, 100);

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
        if(x!=-1)
        {
            t = (struct Node *)malloc(sizeof(struct Node));
            t->data = x;
            t->lchild = t->rchild = NULL;
            p->lchild = t;
            enqueue(&q, t);
        }

        printf("Enter right child of %d: ", p->data);
        scanf("%d", &x);
        if(x!=-1)
        {
            t = (struct Node *)malloc(sizeof(struct Node));
            t->data = x;
            t->lchild = t->rchild = NULL;
            p->rchild = t;
            enqueue(&q, t);
        }
    }
}

void IteratePreorder(struct Node *p)
{
    struct Stack stk;
    Stackcreate(&stk, 100);

    while(p || !isEmptyStack(stk))
    {
        if(p)
        {
            printf("%d ", p->data);
            push(&stk,p);
            p = p->lchild;
        }
        else
        {
            p = pop(&stk);
            p = p->rchild;
        }
    }
}

void IterateInorder(struct Node *p)
{
    struct Stack stk;
    Stackcreate(&stk, 100);

    while(p || !isEmptyStack(stk))
    {
        if(p)
        {
            push(&stk,p);
            p = p->lchild;
        }
        else
        {
            p = pop(&stk);
            printf("%d ", p->data);
            p = p->rchild;
        }
    }
}

void IteratePostorder(struct Node *p)
{
    struct Stack stk;
    Stackcreate(&stk, 100);

    while(p || !isEmptyStack(stk))
    {
        if(p)
        {
            if (p->rchild)
                push(&stk, p->rchild);
            push(&stk, p);

            p = p->lchild;
        }
        else
        {
            p = pop(&stk);
            if (p->rchild && peek(stk) == p->rchild)
            {
                pop(&stk); // remove rchild child from stk
                push(&stk, p); // push p back to stk
                p = p->rchild; // change p so that the rchild
                                    // child is processed next
            }
            else // Else print p's data and set p as NULL
            {
                printf("%d ", p->data);
                p = NULL;
            }
        }
    }
}

int main()
{
    TreeCreate();

    printf("Iterative Preorder: ");
    IteratePreorder(root);
    printf("\n");
    printf("Iterative Inorder: ");
    IterateInorder(root);
    printf("\n");
    printf("Iterative Postorder: ");
    IteratePostorder(root);

    return 0;
}
