/*
Given a Binary search tree. Your task is to complete the function which will return the Kth largest element without doing any modification in Binary Search Tree.

THE FIRST APPROACH WAS TO DO IN-ORDER TRAVERSAL AND ALONGSIDE PUTTING THE DATA IN A MIN_HEAP TO FIND THE Kth LARGEST ELEMENT

THE SECOND APPROACH CAN BE TO DO REVERSE-IN-ORDER TRAVERSAL ALONG WITH KEEPING THE TRACK OF ELEMENTS TRAVELED
WHEN THE NUMBER OF ELEMENTS TRAVELED REACHES K WE SIMPLY RETURN THE ELEMENT
	rev_in_order(root->right);

	k--;
	if(k==0)
		return root->data;

	rev_in_order(root->left);


*/

class Solution
{
    public:
    void inorder(Node* root, priority_queue<int, vector<int>, greater<int>>& hp, int k){
        if(root==NULL)
            return;
            
        inorder(root->left, hp, k);
        hp.push(root->data);
        if(hp.size()>k)
            hp.pop();
        inorder(root->right, hp, k);
    }
    
    int kthLargest(Node *root, int K)
    {
        //Your code here
        priority_queue<int, vector<int>, greater<int>> hp;
        inorder(root, hp, K);
        int res = hp.top();
        return res;
        
    }
};
