#include<bits/stdc++.h>
using namespace std;

class node{
    public:
        int data;
        node* next;
        node* prev;
        node(int val){
            data = val;
            next = prev = NULL;
        }
};

void append(node* &head, int val){
    node* new_node = new node(val);
    node* temp = head;
    if(head==NULL){
        head = new_node;
    }
    else{
        while(temp->next!=NULL){
            temp = temp->next;
        }
        temp->next = new_node;
        new_node->prev = temp;
    }
}

//adds every node to start thus reversing the linked list
void push(node* &head, node* new_node){            
    new_node->prev = NULL;  // since we are adding at the beginning, prev is always NULL
    new_node->next = head; // link the old list off the new node
   
    if (head!= NULL)                  
        head->prev = new_node; // change prev of head node to new node 
   
    head = new_node;       // move the head to point to the new node 
}

node* reverse_k(node* &head, int k){
    node *curr = head; 
    node* nex = NULL; 
    node* newHead = NULL; 
    int count = 0; 

    while (curr != NULL && count < k) 
    { 
        nex = curr->next; 
        push(newHead, curr); 
        curr = nex; 
        count++; 
    } 
      
    if (nex != NULL) 
    { 
        head->next = reverse_k(nex, k);           // after reversing head->next will contain the starting node of next group
        head->next->prev = head;                 //   starting_of_next_grp ->prev = head of previous grp
    } 
      
    return newHead;    // new head of next group
} 

node* reverse_swapping(node* &head, int k){
    node* curr = head;
    node* nex = curr->next;;
    node* temp;
    int count = 0;
    while(nex!=NULL && count<k){
        temp = curr->prev; 
        curr->prev = curr->next;     //swapping next and prev nodes
        curr->next = temp;
        curr = nex;
        nex = nex->next;
        count++;
    }
}