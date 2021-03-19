void populateNext(struct node* p)
{

// Your code goes here
    struct node* next = NULL;
    populateNextRecur(p, &next);

}



void populateNextRecur(node* p, node **next_ref) 
{ 
    if (p) 
    { 
        // First set the next pointer in right subtree 
        populateNextRecur(p->right, next_ref); 
 
        // Set the next as previously visited
        // node in reverse Inorder 
        p->next = *next_ref; 
 
        // Change the prev for subsequent node 
        *next_ref = p; 
 
        // Finally, set the next pointer in right subtree 
        populateNextRecur(p->left, next_ref); 
    } 
} 




/*
    THE MAIN IDEA IS TO RUN IN-ORDER TRAVERSAL IN REVERSE ORDER AND ASSIGNING THE VALUE OF NEXT_REF TO THE NEXT POINTER OF CURRENT ROOT
*/