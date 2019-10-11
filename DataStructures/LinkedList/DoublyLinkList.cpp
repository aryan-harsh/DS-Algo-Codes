/******************************************
* AUTHOR : Mayank Taksande
* NICK : G[~]0ST
* INSTITUTION : IIIT Allahabad
******************************************/


//C++ Program to Implement a Doubly Linked List

#include<iostream>
#include<vector>
#include<string>
#include<deque>
#include<locale>
#include<stack>
#include<set>
#include<utility>
#include<sstream>
#include<algorithm>
#include<chrono>
#include<bits/stdc++.h> 
using namespace std;

// Creating a Node (Basic Element of a Linked List)


struct Node
{
	int value;
	struct Node* prev;
	struct Node* next;
}*start;

// Main Driver Function
class My_Deque
{
public:
	void create_list(int value);
    void push_at_front(int value);
    void push_at(int value, int position);
    void pop_element(int value);
    void search(int value);
    void display();
    void count();
    void reverse();
    My_Deque()
    {
        start = NULL;  
    }
};
int main()
{
	int choice,element,position;
	My_Deque dq;
    while (1)
    {
        cout<<endl<<"----------------------------"<<endl;
        cout<<endl<<"Operations on Doubly linked list"<<endl;
        cout<<endl<<"----------------------------"<<endl;         
        cout<<"1.Create Node"<<endl;
        cout<<"2.Add at begining"<<endl;
        cout<<"3.Add after position"<<endl;
        cout<<"4.Delete"<<endl;
        cout<<"5.Display"<<endl;
        cout<<"6.Count"<<endl;
        cout<<"7.Reverse"<<endl;
        cout<<"8.Quit"<<endl;
        cout<<"Enter your choice : ";
        cin>>choice;
        switch ( choice )
        {
        case 1:
            cout<<"Enter the element: ";
            cin>>element;
            dq.create_list(element);
            cout<<endl;
            break;
        case 2:
            cout<<"Enter the element: ";
            cin>>element;
            dq.push_at_front(element);
            cout<<endl;
            break;
        case 3:
            cout<<"Enter the element: ";
            cin>>element;
            cout<<"Insert Element after postion: ";
            cin>>position;
            dq.push_at(element, position);
            cout<<endl;
            break;
        case 4:
            if (start == NULL)
            {                      
                cout<<"List empty,nothing to delete"<<endl;   
                break;
            }
            cout<<"Enter the element for deletion: ";
            cin>>element;
            dq.pop_element(element);
            cout<<endl;
            break;
        case 5:
            dq.display();
            cout<<endl;
            break;
        case 6:
            dq.count();
            break;    
        case 7:
            if (start == NULL)
            {
                cout<<"List empty,nothing to reverse"<<endl;
                break;
            }
            dq.reverse();
            cout<<endl;
            break;
        case 8:
            exit(1);
        default:
            cout<<"Wrong choice"<<endl;
        }
    }
	return 0;
}

/*
 * Creating Double Link List
 */
void My_Deque::create_list(int info)
{
    struct Node *s, *temp;
    temp = new(struct Node); 
    temp->value = info;
    temp->next = NULL;
    if (start == NULL)
    {
        temp->prev = NULL;
        start = temp;
    }
    else
    {
        s = start;
        while (s->next != NULL)
            s = s->next;
        s->next = temp;
        temp->prev = s;
    }
}
/*
 * Insertion at the beginning or Push_FRONT
 */
void My_Deque::push_at_front(int info)
{
    if (start == NULL)
    {
        cout<<"First Create the list!"<<endl;
        return;
    }
    struct Node *temp;
    temp = new(struct Node);
    temp->prev = NULL;
    temp->value = info;
    temp->next = start;
    start->prev = temp;
    start = temp;
    cout<<"Element Inserted"<<endl;
}
/*
 * Insertion of element at a particular position
 */
void My_Deque::push_at(int info, int pos)
{
    if (start == NULL)
    {
        cout<<"First Create the list."<<endl;
        return;
    }
    struct Node *tmp, *q;
    q = start;
    for (int i = 0;i < pos - 1;i++)
    {
        q = q->next;
        if (q == NULL)
        {
            cout<<"There are less than ";
            cout<<pos<<" elements."<<endl;
            return;
        }
    }
    tmp = new(struct Node);
    tmp->value = info;
    if (q->next == NULL)
    {
        q->next = tmp;
        tmp->next = NULL;
        tmp->prev = q;      
    }
    else
    {
        tmp->next = q->next;
        tmp->next->prev = tmp;
        q->next = tmp;
        tmp->prev = q;
    }
    cout<<"Element Inserted"<<endl;
}

/*
 * Deletion of element from the list or Popping
 */
void My_Deque::pop_element(int info)
{
    struct Node *tmp, *q;
     /*first element deletion*/
    if (start->value == info)
    {
        tmp = start;
        start = start->next;  
        start->prev = NULL;
        cout<<"Element Deleted"<<endl;
        free(tmp);
        return;
    }
    q = start;
    while (q->next->next != NULL)
    {   
        /*Element deleted in between*/
        if (q->next->value == info)  
        {
            tmp = q->next;
            q->next = tmp->next;
            tmp->next->prev = q;
            cout<<"Element Deleted"<<endl;
            free(tmp);
            return;
        }
        q = q->next;
    }
     /*last element deleted*/
    if (q->next->value == info)    
    { 	
        tmp = q->next;
        free(tmp);
        q->next = NULL;
        cout<<"Element Deleted"<<endl;
        return;
    }
    cout<<"Element "<<info<<" not found"<<endl;
}

/*
 * Display elements of Doubly Link List
 */
void My_Deque::display()
{
    struct Node *q;
    if (start == NULL)
    {
        cout<<"List empty,nothing to display"<<endl;
        return;
    }
    q = start;
    cout<<"The Doubly Link List is :"<<endl;
    while (q != NULL)
    {
        cout<<q->value<<" <-> ";
        q = q->next;
    }
    cout<<"NULL"<<endl;
}

/*
 * Number of elements in Doubly Link List
 */
void My_Deque::count()
{ 	
    struct Node *q = start;
    int cnt = 0;
    while (q != NULL)
    {
        q = q->next;
        cnt++;
    }
    cout<<"Number of elements are: "<<cnt<<endl;
}

/*
 * Reverse Doubly Link List
 */
void My_Deque::reverse()
{
    struct Node *p1, *p2;
    p1 = start;
    p2 = p1->next;
    p1->next = NULL;
    p1->prev = p2;
    while (p2 != NULL)
    {
        p2->prev = p2->next;
        p2->next = p1;
        p1 = p2;
        p2 = p2->prev; 
    }
    start = p1;
    cout<<"List Reversed"<<endl; 
}
