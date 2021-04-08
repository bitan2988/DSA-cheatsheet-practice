/*
THREADED BINARY TREE:
	Inorder traversal of a Binary tree can either be done using recursion or with the use of a auxiliary stack. The idea of threaded binary trees is to make inorder
	traversal faster and do it without stack and without recursion. A binary tree is made threaded by making all right child pointers that would normally be NULL point to the inorder successor of the node (if it exists).
																	-------------------------------------------------------------------------------------------------------------------------------------------------------
		There are two types of threaded binary trees. 
			Single Threaded: Where a NULL right pointers is made to point to the inorder successor (if successor exists)
			---------------
			Double Threaded: Where both left and right NULL pointers are made to point to inorder predecessor and inorder 
			---------------	 successor respectively. The predecessor threads are useful for reverse inorder traversal and postorder traversal.
	The threads are also useful for fast accessing ancestors of a node.

	


1. Count the no. of nodes in the given BST using Morris Inorder Traversal.
2- Then Perform Morris Inorder traversal one  more time by counting nodes and by checking if count is equal to the median point. 
   To consider even no. of nodes an extra pointer pointing to the previous node is used.



MORRIS TRAVERSAL
----------------
Morris trvaversal make use ob a threaded binary tree to give  in-order traversal result without making use of any extra-space.
1. Initialize current as root 
2. While current is not NULL
   If the current does not have left child
      a) Print current’s data
      b) Go to the right, i.e., current = current->right
   Else
      a) Find rightmost node in current left subtree OR node whose right child == current.
         If we found right child == current
             a) Update the right child as NULL of that node whose right child is current
             b) Print current’s data
             c) Go to the right, i.e. current = curent->right
         Else
             a) Make current as the right child of that rightmost node we found; and 
             b) Go to this left child, i.e., current = current->left
*/


void morris_in_order(node* root){
	node* curr = root;
	node* pre;

	while(curr!=NULL){

		if(!curr->left){
			cout<<curr->data<<" ";

			curr = curr->right;
		}
		else{
			//FIND IN-ORDER PREDECESSOR OF CURRENT (right-most node on the left sub-tree)
			pre = curr->left;
			while(curr->right!=NULL || pre->right!=curr)
				pre = pre->right;

			//THREAD THE NODE (make curr as the right-child of it's in-order predecessor)
			if(pre->right!=NULL){

				pre->right = curr;
				curr = curr->left;
			}


			//REVERT THE CHANGES MADE TO THE PREDECESSOR NODE
			else{

				pre->right = NULL;
				cout<<curr->data<<" ";

				curr = curr->right;  //MOVING TO THE PREDECESSOR OF CURR NODE
			}
		}
	}
}





//WE CAN USE MORRIS-TRAVERSAL OR WE CAN ALSO USE THE NORMAL RECURSIVE IN-ORDER TO JUST GET THE NUMBER OF NODES
void in_order(node* root, int& count){
	if(root==NULL)
		return;

	in_order(root->left, count);

	count++;

	in_order(root->right);

}

int median(node* root, int k)


int median_util(node* root){

	int total_nodes = 0;

	in_order(root, total_nodes);

	if(total_nodes&1){

		return (median(root, total_nodes/2) + median(root, (total_nodes/2)+1))/2;    //FOR ODD NUMBER OF VALUES MEDIAN = (a[n/2]+a[n/2 + 1])/2;
	}
	else{
		return median(root, total_nodes/2);        //FOR EVEN NUMBER OF VALUES MEDIAN = a[n/2];
	} 
}