//sort a ll od 0, 1 and 2
//we will create 3 dummy node keeping tack of 1,0 and 2 
#include<bits/stdc++.h>
using namespace std;
class node
{
    public:
        node *next;
        int data;

        node(int val)
        {
            data = val;
            next = NULL;
        }
};

void append(node* &head, int val)    //taking by reference as we are modifying the linked list
{
    node* new_node = new node(val);
    if(head==NULL)
    {
        head = new_node;
        return;
    } 
    node* temp = head;
    while(temp->next!=NULL)
    {
        temp = temp->next;
    }
    temp->next = new_node;
}

void printll(node* head)   //taking by value as we are not modifying the linked list in this cae
{                          //even if we move head even then it wont be affected in real linked list
    node* temp = head;
    while(temp!=NULL)
    {
        cout<<temp->data<<"---";
        temp = temp->next;
    }
    cout<<endl;
}

node* sort_zot(node* head){
    node* zero = new node(-1);
    node* resz = zero;     //as result will start from zero 
    node* one = new node(-1);
    node* reso = one;
    node* two = new node(-1);
    node* rest = two;
    node*  temp = head;
    while(temp!=NULL){
        if(temp->data==0){
            zero->next = temp;
            zero = zero->next;
        }
        else if(temp->data==1){
            one->next = temp;
            one = one->next;
        }
        else{
            two->next = temp;
            two = two->next;
        }
        temp = temp->next;
    }
    zero->next = reso->next;
    one->next = rest->next;
    two->next = NULL;
    return resz->next;
}

int main(){
    node* head = NULL;
    for(int i=0;i<15;i++){
        append(head, (i%3));
    }
    printll(head);
    cout<<endl;
    printll(sort_zot(head));
}