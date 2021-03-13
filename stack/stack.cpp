#include<iostream>
using namespace std;
#define stack_max 100

typedef struct
{
    int top;
    int data[stack_max];
} Stack;

void push(Stack *s, int item)
{
    if(s->top < stack_max)
    {
        s->data[s->top] = item;
        s->top = s->top + 1;
    }
    else{
        cout<<"Stack is full!\n";
    }
}

int pop(Stack *s)
{
    int item;

    if(s->top == 0){
        cout<<"Stack is empty!"<<endl;
        return -1;
    }
    else
    {
       s->top = s->top - 1;
       item = s->data[s->top];
    }
    return item;
}

int main()
{
    Stack s1;
    int item;
    s1.top = 0;

    push(&s1, 45);
    push(&s1, 50);
    push(&s1, 55);

    item = pop(&s1);
    cout<<item<<endl;

    item = pop(&s1);
    cout<<item<<endl;

    cout<<s1.top<<endl;

}
