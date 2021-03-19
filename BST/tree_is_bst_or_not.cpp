//CHECH IF A TREE IS A BST OR NOT


return isBSTUtil(root, INT_MIN, INT_MAX);


int isBSTUtil(Node* node, int min, int max) 
{ 
    /* an empty tree is BST */
    if (node==NULL) 
        return 1; 
            
    /* false if this node violates the min/max constraint */
    if (node->data < min || node->data > max) 
        return 0; 
    
    /* otherwise check the subtrees recursively, tightening the min or max constraint */
    return isBSTUtil(node->left, min, node->data-1) && isBSTUtil(node->right, node->data+1, max); 
    //FOR LEFT : all the values of the left sub-tree should be less than the parent value thus we update max
    //FOR RIGHT : all the values of the right sub-tree should be greater than the parent value thus we update min 
} 