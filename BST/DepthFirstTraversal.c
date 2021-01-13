#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *left;
    struct node *right;
};

struct node* create_node(int d)
{
    struct node *temp=(struct node *)malloc(sizeof(struct node));
    temp->data=d;
    temp->left=NULL;
    temp->right=NULL;
    return temp;
}

struct node *add_node(struct node *head, int d)
{
    struct node *temp=create_node(d);
    if(head==NULL)
    {head=temp;
    return head;}
    else if(d<=head->data)
    {
        head->left=add_node(head->left,d);
    }
    else 
    head->right=add_node(head->right,d);
    return head;
}

void inorder(struct node *head)
{
    if(head==NULL)
    return;
    inorder(head->left);
    printf("%d ",head->data);
    inorder(head->right);
    return;
    
}

void preorder(struct node *head)
{
    if(head==NULL)
    return;
    
    printf("%d ",head->data);
    preorder(head->left);
    preorder(head->right);
    return;
    
}

void postorder(struct node *head)
{
    if(head==NULL)
    return;
    postorder(head->left);
    
    postorder(head->right);
    printf("%d ",head->data);
    return;
    
}

int main()
{
    int n,d,i;
    struct node *head=NULL;
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {scanf("%d",&d);
     head=add_node(head,d);
    }
    
    inorder(head);
    printf("\n");
    preorder(head);
    printf("\n");
    postorder(head);
}

