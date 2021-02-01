//https://www.youtube.com/watch?v=mM0EVkKraVw&t=465s
#include <bits/stdc++.h> 
using namespace std; 

class Node { 
public: 
	int data; 
	Node* next; 
}; 

Node* SortedMerge(Node* a, Node* b); 
void FrontBackSplit(Node* source, Node** frontRef, Node** backRef); 

/* sorts the linked list by changing next pointers (not data) --> sorting in place  */
void MergeSort(Node** headRef) 
{ 
	Node* head = *headRef; 
	Node* a; 
	Node* b; 

	/* Base case -- length 0 or 1 */
	if ((head == NULL) || (head->next == NULL)) { 
		return; 
	} 

	/* Split head into 'a' and 'b' sublists */
	FrontBackSplit(head, &a, &b); 

	/* Recursively sort the sublists */
	MergeSort(&a); 
	MergeSort(&b); 

	/* answer = merge the two sorted lists together */
	*headRef = SortedMerge(a, b); 
} 

//merging  two sorted linked list using recursive appproach
Node* SortedMerge(Node* a, Node* b) 
{ 
	Node* result = NULL; 

	if (a == NULL) 
		return (b); 
	else if (b == NULL) 
		return (a); 
	//merging two sorted linked list
	if (a->data <= b->data) { 
		result = a; 
		result->next = SortedMerge(a->next, b); 
	} 
	else { 
		result = b; 
		result->next = SortedMerge(a, b->next); 
	} 
	return result; 
} 

/* Split the nodes of the given list into front and back halves, and return the two lists using the reference parameters. 
	If the length is odd, the extra node should go in the front list.*/
void FrontBackSplit(Node* source, Node** frontRef, Node** backRef) 
{ 
	Node* fast; //moves two step at a time
	Node* slow; //moves one step at  a time
	slow = source; 
	fast = source->next; 

	while (fast != NULL) { 
		fast = fast->next; 
		if (fast != NULL) { 
			slow = slow->next; 
			fast = fast->next; 
		} 
	} 

	*backRef = slow->next; 
	slow->next = NULL; 
} 


void printList(Node* node) 
{ 
	while (node != NULL) { 
		cout << node->data << " "; 
		node = node->next; 
	} 
} 

void push(Node** head_ref, int new_data)  //insert at head
{ 
	Node* new_node = new Node(); 
	new_node->data = new_data; 
	new_node->next = (*head_ref); 
	(*head_ref) = new_node; 
} 


int main() 
{ 
	Node* res = NULL; 
	Node* a = NULL; 

	push(&a, 15); 
	push(&a, 10); 
	push(&a, 5); 
	push(&a, 20); 
	push(&a, 3); 
	push(&a, 2); 

	MergeSort(&a); 

	cout << "Sorted Linked List is: \n"; 
	printList(a); 

	return 0; 
} 


