#include <iostream>
#include <stdio.h>
#include <stdlib.h>
using namespace std;

struct Node {
    int data;
    struct Node* next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

struct Node* addTwoLists(struct Node* first, struct Node* second);

Node* addTwoLists(Node* first, Node* second) {
    
    Node* f=first;
    Node* s=second;
    
    Node* sum =(struct Node*)malloc(sizeof(struct Node*));
    sum->data=-1;
    Node* temp=sum;
    int carry=0;
    int add=0;
    while(f!=NULL || s!=NULL){
        
        int x=0;
        if(f!=NULL){
            x=x+f->data;
            f=f->next;
        }
        if(s!=NULL){
            x=x+s->data;
            s=s->next;
        }
        x=x+carry;
        add=x%10;
        carry=x/10;
        
        Node* e =(struct Node*)malloc(sizeof(struct Node*));
        e->data=add;
        sum->next=e;
        sum=e;
    }

    if(carry==0){
        sum->next=NULL;
    }
    else{
        Node* e =(struct Node*)malloc(sizeof(struct Node*));
        e->data=carry;
        sum->next=e;
        sum=e;
        sum->next=NULL;
    }
    
    return temp->next;
}

void push(struct Node** head_ref, int new_data) {
    struct Node* new_Node = new Node(new_data);
    new_Node->next = (*head_ref);
    (*head_ref) = new_Node;
}
void printList(struct Node* Node) {
    while (Node != NULL) {
        printf("%d ", Node->data);
        Node = Node->next;
    }
    printf("\n");
}
void freeList(struct Node* Node) {
    struct Node* temp;
    while (Node != NULL) {
        temp = Node;
        Node = Node->next;
        free(temp);
    }
}
int main(void) {
    int t, n, m, i, x;
    cin >> t;
    while (t--) {
        struct Node* res = NULL;
        struct Node* first = NULL;
        struct Node* second = NULL;
        cin >> n;
        for (i = 0; i < n; i++) {
            cin >> x;
            push(&first, x);
        }
        cin >> m;
        for (i = 0; i < m; i++) {
            cin >> x;
            push(&second, x);
        }
        res = addTwoLists(first, second);
        printList(res);
        if (first) freeList(first);
        if (second) freeList(second);
    }
    return 0;
}


