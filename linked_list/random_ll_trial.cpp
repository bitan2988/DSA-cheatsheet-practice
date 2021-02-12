//https://www.youtube.com/watch?v=VNf6VynfpdM
//we are given a ll which also have a random pointer which points to any arbitary random pointer 
// we have to make a copy of this ll,  one method use hashmap to store address od copy node in correspondanxce to real node
//but it uses an extra space of O(n), tus we use this method
//here every copy node is made the next noed of its original node and the copies next is made to points to 
//the original nodes next
//         1->1'->2->2'->3->3'    where 1, 2,3 original node and 1', 2', 3'==copy node

void random(node* head){
	node* temp = head;    //keeping track of original ll
	node* nex = NULL;

	//CREATING DEEP COPIES
	while(nex!=NULL){
		nex = temp->next;   //will help in traversing through the original ll and not the deep copy
		node* new_node = new node(temp->data); //creating a new node of same value as temp
		temp->next = new_node;    //pointing temp node to its deep copy    the deep copy lies b/w temp and temp->next
		new_node->next = nex;     // pointing next of new_node to temp->next
		temp = nex;    //moving to the next node of the original ll
	}

	//ASSIGNING RANDOM POINTERS
	node* dummy = new node(-1);     //dummies next will point to the strating of the deep copy
	dummy->next = head->next->next;    //to move throught the original ll
	temp = head; 
	nex = NULL;
	while(nex!=NULL){
		nex = temp->next->next;   //as temp->next is the deep copy and its next is the original node
		temp->next->random = temp->random->next;    //random->next will point to the deep copy of that node
													// and next->random is the random of deep copy
		temp = nex;    //moving throught the original ll
	}

	//RESTORING THE ORIGINAL LINKED LIST
	temp = head;
	nex = temp->next->next;
	while(nex!=NULL){
		temp->next->next = nex->next;  //connecting deep copy to next deep copy
		temp->next = nex;    //connecting original ll nodes
		temp = nex;    //moving to original linked list
	}
	return dummy->next;
}
/*
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        Node *iter = head; 
        Node *front = head;

          // First round: make copy of each node, and link them together side-by-side in a single list.
        while (iter != NULL) {
        	front = iter->next;
			Node *copy = new Node(iter->val);
            iter->next = copy;
            copy->next = front;

            iter = front;
        }

          // Second round: assign random pointers for the copy nodes.
          iter = head;
          while (iter != NULL) {
            if (iter->random != NULL) {
              iter->next->random = iter->random->next;
            }
            iter = iter->next->next;
          }

          // Third round: restore the original list, and extract the copy list.
          iter = head;
          Node *pseudoHead = new Node(0);
          Node *copy = pseudoHead;

          while (iter != NULL) {
            front = iter->next->next;

            // extract the copy
            copy->next = iter->next;

            // restore the original list
            iter->next = front;
              
            copy = copy -> next; 
            iter = front;
          }

          return pseudoHead->next;
    }
};