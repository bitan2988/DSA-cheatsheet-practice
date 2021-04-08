/*
GIVEN TWO BINARY TREE FING SUCH PAIRS(Oone val from tree1 and other one from tree2) WHICH SUM UP TO A GIVEN VALUE   
*/
#include<iostream>
#include<vector>
using namespace std;

class node{
public:
    int data;
    node* right;
    node* left;

    node(int val){
        data = val;
        left = right = NULL;
    }
};



void in_order(node* root, vector<int>& v){
    if(root==NULL)
        return;
        
    in_order(root->left, v);
    v.push_back(root->data);
    in_order(root->right, v);
}
 
int countPairs(node* root1, node* root2, int x)
{
    
    vector<int> v1;
    vector<int> v2;
    
    int count = 0;
    
    in_order(root1, v1);
    in_order(root2, v2);
    
    for(auto it1 : v1){
        for(auto it2 : v2){
            cout<<it1+it2<<"  ";
            if((it1+it2)==x)
                count++;
        }
    }
    
    return count;
    
}


int main(){
    node* root1 = new node(17);
    root1->left = new node(15);
    root1->right = new node(18);
    root1->right->right = new node(19);
    root1->left->left = new node(14);
    root1->left->right = new node(16);

    node* root2 = new node(4);
    root2->left = new node(2);
    root2->right = new node(6);
    root2->left->left = new node(1);
    root2->left->right = new node(3);
    root2->right->right = new node(7);
    root2->right->left = new node(5);

    int res = countPairs(root1, root2, 18);
    cout<<"\nres = "<<res;
}