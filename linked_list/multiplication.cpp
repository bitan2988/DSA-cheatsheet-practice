#include<bits/stdc++.h>
using namespace std;

class node{
    public:
        int data;
        node* next;
        node(int val){
            data = val;
            next = NULL;
        }
};

void append(node* &head, int val){
    node* temp = head;
    node* new_node = new node(val);
    if(head==NULL){
        head = new_node;
    }
    else{
        while(temp->next!=NULL){
            temp = temp->next;
        }
        temp->next = new_node;
    }
}

void print(node* head){
    cout<<endl;
    node* temp = head;
    while(temp!=NULL){
        cout<<temp->data<<"->";
        temp = temp->next;
    }
}

node* rev(node* head){
    node* prev = NULL;
    node* curr = head;
    node* nex = NULL;
    while(curr!=NULL){
        nex = curr->next;
        curr->next = prev;
        prev = curr;
        curr = nex;
    }
    return prev;
}

int count(node* head){
    node* temp = head;
    int count=0;
    while(temp!=NULL){
        count++;
        temp = temp->next;
    }
    return count;
}

long long num_from_ll(node* head){
    long long num = 0;
    int power = (count(head))-1;
    while(power>=0){
        num = num + ((head->data)*pow(10, power));
        power--;
        head = head->next;
    }
    return num;
}

long long multiplication(node* head1, node* head2){
    long long num1 = 0, num2 = 0;
    num1 = num_from_ll(head1);
    num2 = num_from_ll(head2);
    cout<<num1<<"  "<<num2<<endl;
    return num1*num2;
}

int main(){
    node* l1 = NULL;
    node* l2 = NULL;
    for(int i=0;i<10;i++){
        if(i&1){
            append(l1, i);
        }
        else{
            append(l2, i);
        }
    }
    print(l1);
    print(l2);
    //print(rev(l1));
    //print(rev(l2));
    cout<<endl;
    cout<<multiplication(l1, l2);
}