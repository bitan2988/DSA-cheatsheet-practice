/*
For Binary search tree, while traversing the tree from top to bottom the first node which lies in between the two numbers n1 and n2 is the LCA of the nodes, 
i.e. the first node n with the lowest depth which lies in between n1 and n2 (n1<=n<=n2) n1 < n2. So just recursively traverse the BST in, 
if node's value is greater than both n1 and n2 then our LCA lies in the left side of the node,
if it's is smaller than both n1 and n2, then LCA lies on the right side. Otherwise, the root is LCA (assuming that both n1 and n2 are present in BST).
*/

#include<bits/stdc++.h>
using namespace std;

class node{
    public:
        int data;
        node* left;
        node* right;

        node(int val){
            data = val;
            left = right = NULL;
        }
};

node* lca(node* root, int n1, int n2){
    
    if(root==NULL)
        return root;

    if(root->data>n1 && root->data>n2)    //both node lie on the left of root
        return lca(root->left, n1, n2);

    else if(root->data<n1 && root->data<n2)    //both node lie on the right of root
        return lca(root->right, n1, n2);

    return root;
}

int main(){

}


