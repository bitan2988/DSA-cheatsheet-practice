#include<iostream>
#include<bits/stdc++.h>
#include<unordered_map>
using namespace std;

class node
{
    public:
    	node* next;
    	int data;
    	node(int val)
    	{
    		data = val;
    		next = NULL;
		}
};

void append(node* &head, int val)
{
	node* leaf = new node(val);
	node* temp = head;
	if(head==NULL)
	{
		head = leaf;
	}
	else
	{
		while(temp->next!=NULL)
		{
			temp = temp->next;
		}
		temp->next = leaf;
	}
}

void print(node* head)
{
	node* temp = head;
	while(temp!=NULL)
	{
		cout<<temp->data<<"--";
		temp = temp->next;
	}
}

void duplicate_in_unsorted_ll(node* &head)
{
	unordered_set<int> seen;
    node* curr = head;
    node* prev = NULL;
    while (curr != NULL)
    {
        // If current value is seen before
        if (seen.find(curr->data) != seen.end())
        {
           prev->next = curr->next;
           delete (curr);
        }
        else
        {
           seen.insert(curr->data);
           prev = curr;
        }
        curr = prev->next;
    }
}

int main()
{
    node* head = NULL;
    append(head, 10);
    append(head, 80);
    append(head, 90);
    append(head, 20);
    append(head, 30);
    append(head, 40);
    append(head, 50);
    append(head, 60);
    append(head, 70);
    append(head, 80);
    print(head);
    cout<<endl;
    duplicate_in_unsorted_ll(head);
    print(head);
    return 0;
}
