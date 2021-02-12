//Delete a node if there exists a node greater than it on right
// 1. Reverse the linked list
// 2. traverse from start and keep max_till_node
// 3. if value less than it then delete else update max till now

node* rev(node* head){
	node* prev = NULL;
	node* curr = head;
	node* nex;
	while(curr!=NULL){
		nex = curr->next;
		curr->next = prev;
		prev = curr;
		curr = nex;
	}
	return prev;
}

node* right_g(node* head){
	node* temp = rev(head);
	node* to_be_deleted = NULL;
	int mtn = INT_MIN;
	while(temp->next!=NULL){
		if(temp->next->data>mtn){
			mtn = temp->data;
			temp = temp->next;
		}
		else{
			temp->next = temp->next->next;
			to_be_deleted = temp;
			delete(to_be_deleted);
		}
	}
}