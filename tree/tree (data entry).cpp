#include<iostream>
#include<stdlib.h>
using namespace std;

struct node
{
    int data;
    struct node *left, *right;
};

struct node* create()
{
   int x;
   struct node *newnode;
   newnode = (struct node *)malloc(sizeof(struct node));

   cout<<"Enter data (-1 for no node) : ";
   cin>>x;
   if(x == -1)
   {
       return 0;
   }
   newnode->data=x;

   cout<<"Enter left child of "<<x<<endl;
   newnode->left = create();

   cout<<"Enter right child of "<<x<<endl;
   newnode->right = create();

   return newnode;
}

void preorder(struct node *root)
{
    if(root == 0)
    {
        return;
    }
    cout<<root->data<<" ";
    preorder(root->left);
    preorder(root->right);
}

void inorder(struct node *root)
{
    if(root == 0)
    {
        return;
    }
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}

void postorder(struct node *root)
{
    if(root == 0)
    {
        return;
    }
    postorder(root->left);
    postorder(root->right);
    cout<<root->data<<" ";
}

int main()
{
    struct node *root;
    root = create();

    cout<<"Pre-order is: ";
    preorder(root);

    cout<<"In-order is: ";
    inorder(root);

    cout<<"Post-order is: ";
    postorder(root);
}
