#include<bits/stdc++.h>
using namespace std;

class node{
    public:
        int data;
        node* left;
        node* right;
        node(int val){
            data = val;
            right = NULL;
            left = NULL;
        }
};

void in_order(node* root){
    if(root==NULL)
        return;
    in_order(root->left);
    cout<<root->data<<" ";
    in_order(root->right);
}



//adjacent nodes are those which are left/right child of the current node
pair<int, int> not_adjacent(node* root){
    
    if(root==NULL){
        pair<int, int> sum(0, 0);
        return sum;
        }
    
    pair<int, int> sum_left = not_adjacent(root->left);      //pair<if_included, if_not_included>
    pair<int,int> sum_right = not_adjacent(root->right);
    pair<int, int> sum;

    //if the node is not-included then call for the right and the left child
    //and return max of if for both the max values of including and not-including the left/right node
    sum.second = max(sum_left.first, sum_left.second) + max(sum_right.first, sum_right.second);   

    //if the current node is included then the left&right child are not included
    sum.first = sum_left.second + sum_right.second + root->data;

    return sum;
}

void printVector(const vector<int>& v, int i) 
{ 
    for(int j=i; j<v.size(); j++) 
        cout<<v[j]<<" "; 
    cout<<endl; 
} 
//k-sum paths
void k_sum(node* root, vector<int> &path, int k){

    if(root==NULL)
        return;
    //pre-order traversal to cover all the nodes
    path.push_back(root->data);
    k_sum(root->left, path, k);   //checking if a k-sum path exists in the left sub-tree
    k_sum(root->right, path, k); //checking if a k-sum path exists in the right sub-tree
    //if a path till the current-node has a summ equal to k then print that path
    int f = 0;
    for(int j=path.size()-1;j>=0;j--){
        f += path[j];

        if(f==k){
            printVector(path, j);
        }
    }
    //remove all the values the current path
    path.pop_back();
}



//Lowest-common-ancestor
/* 
The node which has one key present in its left subtree and the other key present in the right subtree is the LCA. 
If both keys lie in the left subtree, then the left subtree has LCA also, otherwise, LCA lies in the right subtree.
*/
node* lca(node* root ,int n1 ,int n2 )
    {
        if(root==NULL)
            return NULL;

        //if the data matches any of the values then the current root is the ancestor
        if(root->data==n1 || root->data==n2)
            return root;
        
        //if it doesn,t matches look in the right and the left sub-tree
        node* l = lca(root->left, n1, n2);
        node* r = lca(root->right, n1, n2);
        
        //if one is found in the right sub-tree and another in the left sub-tree then return the current root
        if(l&&r)
            return root;
        
        if(l==NULL)   //if both found in right sub-tree
            return r;
        else   //if both found in left sub-tree
            return l;
    }

int findDistance(node* root, int x)
{
    // Base case
    if (root == NULL)
      return -1;
 
    // Initialize distance
    int dist = -1;
 
    // Check if x is present at root or in left-subtree or right-subtree.
    if ((root->data == x) || (dist = findDistance(root->left, x)) >= 0 || (dist = findDistance(root->right, x)) >= 0)
        return dist + 1;
 
    return dist;
}
//MINIMUM DISTANCE BETWEEN TWO NODES
//Dist(n1, n2) = Dist(root, n1) + Dist(root, n2) - 2*Dist(root, lca)
int min_dist(node* root, int n1, int n2){

    if(root==NULL)
        return -1;

    //considering both are present in the tree
    //First find their least-common-ancestor
    node* lc = lca(root, n1, n2);

    //find the distance of lca from root
    int l = findDistance(root, lc->data);

    //find level of n1
    int l1 = findDistance(root, n1);

    //find level of n2
    int l2 = findDistance(root, n2);

    int distance = l1 + l2 - (2*l);     //Dist(n1, n2) = Dist(root, n1) + Dist(root, n2) - 2*Dist(root, lca)

    return distance;
}



//K-th ANCESTOR
//we simply look for the node using DFS keeping a track of k 
//if the node is found then we move upward while decremting k and printing the root ass it turns zero
node* k_ancestor(node* root, int key, int& k){

    if(root==NULL)
        return NULL;

    if(root->data==key || k_ancestor(root->left, key, k) || k_ancestor(root->right, key, k)){
    
    if(k>0)
        k--;

    else if(k==0){
           cout<<root->data; 
           return NULL;
        }

    return root;
    }
    
}



//PRINT ALL DUPLICATE SUB-TREES WITHIN A TREE
//Use in-order traversal along with special symbols to represent NULL
string dup(node* root, unordered_map<string, int>& umap){

    if(root==NULL)
        return "'";

    string s = "(";
    s += dup(root->left, umap);
    s += to_string(root->data);
    s += dup(root->right, umap);
    s += ")";

    if(umap[s]==1)     //one indicate that string has already appeared
        cout<<root->data<<" ";
    
    umap[s]++;   //updating value part of  that key to 1

    return s;
}



//ISO-MORPHIC TREE A.K.A MIRROR IMAGES
bool isomorphic(node* n1, node* n2){
     if (n1 == NULL && n2 == NULL) 
    return true; 
  
 // Exactly one of the n1 and n2 is NULL, trees not isomorphic 
    if (n1 == NULL || n2 == NULL) 
        return false; 
    
    if (n1->data != n2->data) 
        return false; 
    
    // There are two possible cases for n1 and n2 to be isomorphic 
    // Case 1: The subtrees rooted at these nodes have NOT been "Flipped". 
    // Both of these subtrees have to be isomorphic, hence the && 
    // Case 2: The subtrees rooted at these nodes have been "Flipped" 
    return (isomorphic(n1->left,n2->left) && isomorphic(n1->right,n2->right))|| (isomorphic(n1->left,n2->right) && isomorphic(n1->right,n2->left));
}


int main(){
    node* root = new node(1);
    root->left = new node(3);
    root->right = new node(-1);
    root->left->left = new node(2);
    root->left->right = new node(1);
    root->left->right->left = new node(1);
    root->right->left = new node(4);
    root->right->right = new node(5);
    root->right->right->right = new node(6);
    root->right->left->left = new node(1);
    root->right->left->right = new node(2);
    //in_order(root);
    vector<int> path;
    k_sum(root, path, 5);
    cout<<"\n";
    pair<int, int> res;
    //res = not_adjacent(root);
    cout<<max(res.first, res.second);

    unordered_map<string, int> umap;
}