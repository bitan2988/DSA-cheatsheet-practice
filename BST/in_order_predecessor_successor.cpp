
//You need to find the inorder successor and predecessor of a given key. In case the given key is not found in BST, 
//then return the two values within which this key will lie.

/*
If root is NULL
      then return
2. if key is found then
    a. If its left subtree is not null
        Then predecessor will be the right most 
        child of left subtree or left child itself.
    b. If its right subtree is not null
        The successor will be the left most child 
        of right subtree or right child itself.
    return
3. If key is smaller then root node
        set the successor as root
        search recursively into left subtree
    else
        set the predecessor as root
        search recursively into right subtree
*/


void pre_suc(node* root, int key, int& predecessor, int& successor)
{
	if(root==NULL)
		return;

	if(root->data==key){
		node* temp;

		if(root->left!=NULL){
			while(root->right!=NULL)
				temp = root->right;

			predecessor = temp->data;
		}
		if(root->right!=NULL){
			while(root->left!=NULL)
				temp = root->left;

			successor = temp->data;
		}

		return;
	}

	if(key < root->data){

		successor = root->data;
		pre_suc(root->left, key, predecessor, successor)
	}
	else{

		predecessor = root->data;
		pre_suc(root->right, key, predecessor, successor)
	}
}




/*
Another Approach : 
	We can also find the inorder successor and inorder predecessor using inorder traversal . 
	Check if the current node is smaller than the given key for predecessor and for successor, check if it is greater than the given key . 
	If it is greater than the given key then, check if it is smaller than the already stored value in successor then, update it . 
	At last, get the predecessor and successor stored in q(successor) and p(predecessor).
*/

void find_p_s(Node* root,int key, Node** p, Node** q)
{
    // If root is null return 
    if(!root)
        return ;
         
    // traverse the left subtree    
    find_p_s(root->left, key, p, q);
     
    // root data is greater than key
    if(root && (root->data > key))
    {
         
        // q stores the node whose data is greater than key and is smaller than the previously stored data in *q which is sucessor
        if((!*q) || (*q) && ((*q)->data > root->data))
                *q = root;
    }
     
    // if the root data is smaller then store it in p which is predecessor
    else if(root && (root->data < key))
    {
        *p = root;
    }
     
    // traverse the right subtree
    find_p_s(root->right, key, p, q);
}