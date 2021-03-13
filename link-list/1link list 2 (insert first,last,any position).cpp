#include<iostream>
#include<stdlib.h>
using namespace std;

struct node
{
    int data;
    struct node *next;
};

struct node* head =0,* temp;
int count=0;
void push_first(int new_data)
{

    struct node* newnode = (struct node*) malloc(sizeof(struct node));

    newnode->data = new_data;
    newnode->next = head;
    head=newnode;
    count++;
}

void push_last(int new_data)
{

    struct node* newnode = (struct node*) malloc(sizeof(struct node));

    newnode->data = new_data;
    newnode->next = 0;
    temp=head;

    while(temp->next != 0){
       temp = temp->next;
    }
    temp->next = newnode;
    count++;
}

void push_position(int position, int new_data)
{
    if(position==count+1){
        push_last(new_data);
    }
    else if(position==1){
        push_first(new_data);
    }
    else if(position>count){
        cout<<"Invalid Position"<<endl;
    }
    else
    {
        struct node* newnode = (struct node*) malloc(sizeof(struct node));
        temp=head;
        int i=2;
        while(i<position){
           temp = temp->next;
           i++;
        }
        newnode->data = new_data;
        newnode->next = temp->next;
        temp->next = newnode;
        count++;
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
    push_first(3);
    push_last(4);
    push_first(5);
    push_last(6);
    push_position(3,40);
    cout<<"The linked list is: ";
   show();

   cout<<endl;
   //cout<<count;
   return 0;
}

