#include<iostream>
using namespace std;

void push(int data);
void prnt(void);

struct node
{
    int data;
    struct node * next;
    node(int data)                                             //Contructor will be automatically called when called by NEW
    {
        this->data = data;
        next = NULL;
    }
};

struct node* head = NULL;
struct node* temp = NULL;
struct node* prev = NULL;

int main()
{
    push(5);
    push(6);
    push(7);
    prnt();
    return 0;
}


void push(int data)
{
    cout<<"Entering data "<<data;
    node* curr = new node(data);
    if(head==NULL)
    {
        head = curr;
    }
    if (prev==NULL)
    {
        prev=curr;
        
    }
    else
    {
        prev->next=curr;
    }
    curr->next=NULL;
    cout<<"          prev->next = "<<prev->next;
    prev=curr;
    //cout<<"       intitial curr->next = "<<curr->next;
    curr->next=NULL;
    cout<<"          curr = "<<curr;
    
    cout<<"\n";

    
    
}

void prnt(void)
{
    //temp = head;
    temp = head;
    do
    {
        cout<<temp->data<<"---";
        temp = temp->next;
    }while(temp!=NULL);
}


