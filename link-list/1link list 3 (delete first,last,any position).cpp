#include<iostream>
#include<stdlib.h>
using namespace std;

struct node
{
    int data;
    struct node *next;
};

//insert  functions
struct node* head =0, *temp;

void push(int new_data)
{

    struct node* newnode = (struct node*) malloc(sizeof(struct node));

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
    temp = head;
    while(temp !=0){
        cout<<temp->data<<" ";
        temp=temp->next;
    }

}

//delete functions

void delete_first()
{
    if(head==0)
    {
        cout<<"list is empty";
    }
    else
    {
        temp = head;
        head = head->next;
        free(temp);
    }
}

void delete_last()
{
    struct node *prevnode;
    temp = head;
    while(temp->next !=0)
    {
        prevnode = temp;
        temp = temp->next;
    }
    if(temp==head)
    {
        head=0;
    }
    else
    {
        prevnode->next=0;
    }
    free(temp);
}

void delete_position(int position)
{
    struct node *nextnode;
    int i=1;
    temp=head;
    while(i<position-1)
    {
        temp = temp->next;
        i++;
    }
    nextnode = temp->next;
    temp->next = nextnode->next;
    free(nextnode);
}

int main()
{
    push(3);
    push(4);
    push(5);
    push(6);
    push(7);
    push(8);
    push(9);
    push(10);
    delete_first();
    delete_last();
    delete_position(3);
    cout<<"The linked list is: ";
   show();
   return 0;
}

