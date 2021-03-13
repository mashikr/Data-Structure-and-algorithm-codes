#include<iostream>
using namespace std;
#define que_max 5

typedef struct
{
    int head, tail;
    int data[que_max + 1];
} Queue;

void enqueue(Queue *q, int item)
{
    if((q->tail + 1) % (que_max + 1) == q->head)
    {
        cout<<"Queue is full"<<endl;
        return;
    }
    q->data[q->tail] = item;
    q->tail = (q->tail + 1) % (que_max + 1);
}

int dequeue(Queue *q)
{
    int item;

    if(q->tail == q->head){
        cout<<"Queue is empty"<<endl;
        return -1;
    }
    item = q->data[q->head];

    q->head = (q->head + 1) % (que_max + 1);

    return item;
}

int main()
{
    Queue q;
    int item;
    q.head = 0;
    q.tail = 0;

    enqueue(&q, 40);
    enqueue(&q, 50);
    enqueue(&q, 60);

    item = dequeue(&q);
    cout<<item<<endl;
    item = dequeue(&q);
    cout<<item<<endl;
    cout<<q.head<<" "<<q.tail<<endl;
}
