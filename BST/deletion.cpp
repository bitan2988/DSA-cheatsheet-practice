
//https://www.youtube.com/watch?v=gcULXE7ViZw
//DELETE A NODE IN BST
/*
case 1: LEAF NODE - just remove  the node as it wont effect the overallbalance of the tree
case 2: ONLY ONE-CHILD - in this case replace the deleted node with it's child node having on children and point the deleted(now replaced node) to it's grand-children
case 3: HAVE TWO-CHILD - we replace the deleted node with the minimum value in the right sub-tree and it will reduce to case 1/2 by the prop of a bst
		|
		-->The node with minimum value will definitely not have a left child(as left child shouls have a value lesser than parent but it's already the min) and may/maynot have a right child
			|
			-->if it have a right child then the problem reduces to case 2
			|
			-->if it doesn't have a right child then the case reduces to case 1
*/
#include<bits/stdc++.h>
using namespace std;


class node{
public:
	int data;
	node* left;
	node* right;

	node(int val){
		data = val;;
		left = right = NULL;
	}
};


//The minimum value node will be the left-most node
node* find_min(node* root){
	while(root->left!=NULL)
		root = root->left;

	return root;
}

node* deletion(node* root, int key){

	if(root==NULL)
		return root;

	//if key value node is not found
	else if(key < root->data)
		root->left = deletion(root->left, key);
	else if(key > root->data)
		root->right = deletion(root->right, key);

	//found node with value key
	else{

		//case 1 : leaf node
		if(root->left==NULL && root->right==NULL){
			delete root;
			root = NULL;
		}

		//if only have right child
		else if(root->left==NULL){
			node* temp = root;
			root = root->right;
			delete(temp);

		}

		//if only have left child
		else if(root->right==NULL){
			node* temp = root;
			root = temp->left;
			delete(temp);
		}

		//case 3: have both lef tand right child
		else{
			//find the minimum node in the right sub-tree
			node* temp = find_min(root->right);
			//assigning data to the targeted node
			root->data = temp->data;
			//as it will again move back to case 1/2 thus we again call the function for that node
			root->right = deletion(root->right, temp->data);

		}
	}
	return root;
}






int main(){
	node* root = new node(1);
	deletion(root, 1);
}
