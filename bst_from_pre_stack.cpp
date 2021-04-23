/*
1. Create an empty stack.

2. Make the first value as root. Push it to the stack.

3. Keep on popping while the stack is not empty and the next value is greater than stack’s top value. Make this value as the right child of the last popped node. Push the new node to the stack.

4. If the next value is less than the stack’s top value, make this value as the left child of the stack’s top node. Push the new node to the stack.

5. Repeat steps 2 and 3 until there are items remaining in pre[].
*/

#include<iostream>
#include<stack>
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


stack<node*> st;

node* make_bst(stack<node*> st, int pre[], int size){

    int root_data = pre[0];
    
    node* root = new node(root_data);
    st.push(root);

    int i;

    for(i=0; i<size; ++i){

        node* temp = NULL;

        while(!st.empty() && pre[i] > root_data)
            st.pop();

        if(temp!=NULL){
            temp->right = new node(pre[i]);
            st.push(temp->right);
        }

        else{
            st.top()->left = new node(pre[i]);
            st.push(root->left);
        }    
    }

    return root;
}

void pre_order(node* root){
    if(root==NULL)
        return;

    cout<<root->data<<" ";
    pre_order(root->left);
    pre_order(root->right);
}

int main(){
    int pre[] = {5, 3, 2, 1, 4, 7, 6, 8};

    int size = sizeof(pre)/sizeof(pre[0]);

    node* root = make_bst(st, pre, size);
    pre_order(root);

    cout<<endl;
}