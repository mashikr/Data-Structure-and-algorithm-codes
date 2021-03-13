#include<iostream>
#include<stdlib.h>
using namespace std;

struct node
{
    int data;
    struct node *next;
};

struct node* head =0;

void push(int new_data)
{

    struct node* newnode = (struct node*) malloc(sizeof(struct node));
    struct node* temp;

    newnode->data = new_data;
    newnode->next = 0;

    if(head == 0)
    {
        head = temp = newnode;

    }
    else
    {
        temp->next = newnode;
        temp = newnode;
    }
}

void show()
{
    struct node* ptr;
    ptr = head;
    while(ptr !=0){
        cout<<ptr->data<<" ";
        ptr=ptr->next;
    }

}

int main()
{
    push(3);
    push(4);
    push(5);
    push(6);
    cout<<"The linked list is: ";
    show();
    return 0;
}
