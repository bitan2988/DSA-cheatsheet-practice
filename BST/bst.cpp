#include<bits/stdc++.h>
using namespace std;

class node{
    public:
        int data;
        node* left;
        node* right;

        node(int val){
            data = val;
            left = NULL;
            right = NULL;
        }
};



//SEARCHING TAKES logN AS AFTER EVERY i STEP WE ARE REMOVING N/2**i NODES
node* search(node* root, int key){

    if(root==NULL || root->data==key)
        return root;

    if(root->data > key)
        return search(root->left, key);
    else
        return search(root->right, key);
}


//INSERTION ALWAYS TAKES PLACE AT THE LEAF NODE
node* in(node* root, int val){

    if(root==NULL)
        return new node(val);   //if reached a leaf node insert at that point

    if(val > root->data)
        root->right = in(root->right, val);   //if val is greater than root then move towards right-child
    else
        root->left = in(root->left, val);    //if val is lesser than root then move towards lefft-child
    
    return root;
}



//IN-ORDER TRAVERSAL OF A BST SHOULD GIVE A SORTED ARRAY(ASC) 
void in_order(node* root){
    if(!root)
        return;

    in_order(root->left);
    cout<<root->data<<" ";
    in_order(root->right);
}




int main(){

    node* root = new node(10);
    root->left = new node(9);
    root->right = new node(11);
    root->left->left = new node(8);
    root->left->right = new node(12);
    root->right->left = new node(7);
    root->right->right = new node(13);

    node* s = search(root, 7);
    cout<<"Searched "<<s->data;
    cout<<"IN-ORDER\n";
    in_order(root);
    in(root, 15);
    cout<<"\n";
    in_order(root);

}