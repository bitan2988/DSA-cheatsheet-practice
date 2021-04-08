/*
Input:                                                   Output
       30                                                    
      /
     20                  --->                              20
    /                                                      /\
   10                                                    10  30
WE FIRST TEAVERSE THE BST IN-ORDER AND THEN STORE THE VALUE IN AN ARRAY, THEN WE CREATE A BALANCED BST USING THAT ARRAY USING THE BELOW ALGO:
    1) Get the Middle of the array and make it root.
    2) Recursively do same for left half and right half.
        a) Get the middle of left half and make it left child of the root
            created in step 1.
        b) Get the middle of right half and make it right child of the
            root created in step 1.
*/
#include<iostream>
#include<vector>
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

vector<int> v;

void in_order(node* root){
    if(root==NULL)
        return;

    in_order(root->left);
    v.push_back(root->data);
    in_order(root->right);
}

node* balanced_bst_from_sorted_array(int low, int high){
    if(low > high)
        return NULL;

    int mid = (low + high)/2;

    node* root = new node(v[mid]);

    root->left = balanced_bst_from_sorted_array(low, mid-1);

    root->right = balanced_bst_from_sorted_array(mid+1, high);

    return root;
}

node* balanced_bst_util(node* root){
    if(root==NULL)
        return root;

    in_order(root);

    return balanced_bst_from_sorted_array(0, v.size()); 
}


int main(){
    node* root = new node(30);
    root->left = new node(20);
    root->left->left = new node(10);

    node* new_root = balanced_bst_util(root);

    cout<<new_root->data<<" "<<new_root->left->data<<" "<<new_root->right->data;
}



