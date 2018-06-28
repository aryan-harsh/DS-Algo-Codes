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

struct qnode{
    struct node *nod;
    struct qnode *next;
};

struct qnode *enqueue(struct qnode *qhead,struct node *nod)
{
    struct qnode *temp=(struct qnode *)malloc(sizeof(struct qnode));
    temp->nod=nod;
    temp->next=NULL;
    if(qhead==NULL)
    {qhead=temp;
     return qhead;}
    else
    {
        struct qnode *temp1;
        temp1=qhead;
        while(temp1->next!=NULL)
        temp1=temp1->next;
        temp1->next=temp;
        return qhead;
    }
}

struct node *dequeue(struct qnode *qhead)
{
    if(qhead==NULL)
    return;
    else
    {qhead=qhead->next;
    
    return qhead;}
}

struct node *top(struct qnode *qhead)
{
    if(qhead==NULL)
    return;
    else {
    struct node *temp;
    temp=qhead->nod;
    return temp;}
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

void bft(struct node *head)
{
    if(head==NULL)
    return;
    else 
    {
        struct qnode *qhead=NULL;
        qhead=enqueue(qhead,head);
        while(qhead!=NULL)
        {
            struct node *temp=top(qhead);
            printf("%d ",temp->data);
            if(temp->left!=NULL)
             qhead=enqueue(qhead,temp->left);
            if(temp->right!=NULL)
             qhead=enqueue(qhead,temp->right);
             qhead=dequeue(qhead);
        }
    }
    
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
    bft(head);
}

