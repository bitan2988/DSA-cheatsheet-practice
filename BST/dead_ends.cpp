/*
If we take a closer look at the problem, we can notice that we basically need to check if there is a leaf node with value x such that x+1 and x-1 exist in BST 
with the exception of x = 1. For x = 1, we can’t insert 0 as the problem statement says BST contains positive integers only.
To implement the above idea we first traverse the whole BST and store all nodes in a hash_map. We also store all leaves in a separate hash to avoid re-traversal of BST. 
Finally, we check for every leaf node x, if x-1 and x+1 are present in hash_map or not.
Below is a C++ implementation of the above idea. 
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



void in_order(node* root, unordered_set<int> &nodes, unordered_set<int> &end_nodes){
    if(root==NULL)
        return; 

    if(root->left==NULL && root->right==NULL){
        nodes.insert(root->data);
        end_nodes.insert(root->data);
        return;
    }
        

    if(root->left)
        in_order(root->left, nodes, end_nodes);

    nodes.insert(root->data);

    if(root->right)
        in_order(root->right, nodes, end_nodes);
}

bool dead_ends(node* root, unordered_set<int> nodes, unordered_set<int> end_nodes){

    if(root==NULL)
        return false;

    for(auto i=end_nodes.begin(); i!=end_nodes.end(); i++){

        int val = *i;

        for(auto j=nodes.begin(); j!=nodes.end(); j++){
            int v = *j;

            if(v==val+1 || v==val-1 || v==1)
                return false;
        }
    }

    return true;
}

int main(){
    unordered_set<int> nodes;
    unordered_set<int> end_nodes;

    node* root = new node(8);
    root->left = new node(5);
    root->left->left = new node(2);
    root->left->left->left = new node(1);
    root->left->right = new node(7);
    root->right = new node(9);


    in_order(root, nodes, end_nodes);

    for(auto it:nodes)
        cout<<it<<" ";

    cout<<endl;

    for(auto it:end_nodes)
        cout<<it<<" ";

    cout<<endl;
}

