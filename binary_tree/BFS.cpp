/*        C++ program to print level order traversal using STL 
BREADTH FIRST SEARCH    -->  PRINT ALL NODES ON THE CURRENT LEVEL     */
#include <bits/stdc++.h>
using namespace std;

class node
{
	public:
		int data;
		node* left;
		node* right;
		node(int val){
			data = val;
			left = right = NULL;
	}
};

void rev_bfs(node* root){
	queue<node*> q;
	stack<node*> s;
	node* temp;
	if(root==NULL)
		return;
	else{
		q.push(root);
		while(q.empty()==false){
			temp = q.front();
			s.push(temp);
			q.pop();
			if(temp->right!=NULL)       //right goes first
				q.push(temp->right);
			if(temp->left!=NULL)       //then left
				q.push(temp->left);
		}
	}
	while(s.empty()==false){         //stack will store the same as queue but when pop is called it o/p in reverse order
		temp = s.top();
		cout<<temp->data<<" ";
		s.pop();
	}
}

// Iterative method to find height of Binary Tree
//the queue processes in such a way that it moves from left to right in a level
void printLevelOrder(node *root)
{
	/*
	root->left->left->right
	root->left->left->left
	root->right->right
	root->right->left
	root->left->right
	root->left->left
	root->right
	root->left
	root
	*/
	// Base Case
	if (root == NULL) 
        return;

	// Create an empty queue for level order traversal
	queue<node *> q;

	// Enqueue Root and initialize height
	q.push(root);

	while (q.empty() == false)
	{
		// Print front of queue and remove it from queue
		node* temp = q.front();
		cout << temp->data << " ";
		q.pop();

		/* Enqueue left child */
		if (temp->left != NULL)
			q.push(temp->left);

		/*Enqueue right child */
		if (temp->right != NULL)
			q.push(temp->right);
	}
}


// Driver program to test above functions
int main()
{
	// Let us create binary tree shown in above diagram
	node *root = new node(1);
	root->left = new node(2);
	root->right = new node(3);
	root->left->left = new node(4);
	root->left->right = new node(5);
    root->right->left = new node(6);
    root->right->right = new node(7);
    root->left->left->left = new node(8);
    root->right->right->right = new node(9);

	cout << "Level Order traversal of binary tree is \n";
	printLevelOrder(root);
	cout<<endl;
	rev_bfs(root);
	return 0;
}
