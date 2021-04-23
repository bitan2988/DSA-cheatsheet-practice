/*Create a dummy node.
	Create a variable called ‘prev’ and make it point to the dummy node.
	Perform in-order traversal and at each step.
		Set prev -> right = curr
		Set prev -> left = NULL
		Set prev = curr
This will improve the space complexity to O(H) in worst case as in-order traversal takes O(H) extra space.*/


#include<iostream>
using namespace std;

class Node{
public:
	int data;
	node* left;
	node* right;

	node(int val){
		data = val;
		left = right = NULL;
	}
};

void in_order(Node* root, Node* prev){
	if(root==NULL)
		return;

	in_order(root->left, prev);

	prev->right = root;      //prev will have dummy for first iteration and will subsequently have values as per the in_order traversal takes place
	prev->left = NULL;
	prev = root;

	in_order(root->right, prev);
}

Node* flatten(Node* parent)
{
    // Dummy node
    Node* dummy = new node(-1);
  
    // Pointer to previous element
    Node* prev = dummy;
  
    // Calling in-order traversal
    inorder(parent, prev);
  
    prev->left = NULL;    //for the last node i.e the node with highest value we set both the left and right nodes as NULL
    prev->right = NULL;
    Node* ret = dummy->right;
  
    // Delete dummy node
    delete dummy;
    return ret;
}
