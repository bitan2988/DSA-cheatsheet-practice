#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class node
{
    public:
        node *next;
        int data;

        node(int val)
        {
            data = val;
            next = NULL;
        }
};

void append(node* &head, int val)    //taking by reference as we are modifying the linked list
{
    node* new_node = new node(val);
    if(head==NULL)
    {
        head = new_node;
        return;
    } 
    node* temp = head;
    while(temp->next!=NULL)
    {
        temp = temp->next;
    }
    temp->next = new_node;
}

void printll(node* head)   //taking by value as we are not modifying the linked list in this cae
{                          //even if we move head even then it wont be affected in real linked list
    node* temp = head;
    while(temp!=NULL)
    {
        cout<<temp->data<<"---";
        temp = temp->next;
    }
    cout<<endl;
}

void deletenode(node* &head, int val)
{
    node* todelete;
    node* temp = head;
    if(temp==head and temp->data==val)
    {
        todelete = head;
        head = head->next;
        delete todelete;
        return;
    }
    while(temp->next->data!=val)
    {
        temp = temp->next;
    }
    todelete = temp->next;
    temp->next = temp->next->next;
    delete todelete;
}

void reverse(node* &head)
{
    node* prev = NULL;
    node* curr = head;
    node* later  = head->next;
    while(curr->next!=NULL)
    {
        curr->next = prev;
        prev = curr;
        curr = later;
        later = later->next;
    }
    curr->next = prev;
    head = curr;
}

int count(node* head)
{
    int total_nodes = 0;
    node* temp = head;
    while(temp!=NULL)
    {
        total_nodes++;
        temp = temp->next;
    }
    return total_nodes;
}

node* insert_middle(node* &head,  int n, int val)
{
    if(n==1)
    {
        node* new_node = new node(val);
        new_node->next = head;
        head = new_node;
        return head;
    }
    else
    {
        int i = 0;
        node* temp = head;
        while(temp!= NULL and i<n-2)
        {
            temp = temp->next;
            i++;
        }
        node* nex = temp->next;
        node* new_node = new node(val);
        temp->next = new_node;
        new_node->next = nex;
        return head;
    }
}

node* detect_cycle(node* head)      //detect a cycle in ll by using Floy's loop detection 
{
    //https://www.youtube.com/watch?v=-YiQZi3mLq0&t=198s
    node* hare = head;   //moves two steps
    node* tort = head;   //moves one step
    while(hare!=NULL and hare->next!=NULL)
    {
        hare = hare->next->next;
        tort = tort->next;
        if(hare==tort)
        {
            return tort;
        }
    }
    return head;
/*   Now if consider movements of slow and fast pointers, we can notice that distance between them
 (from slow to fast) increase by one after every iteration. After one iteration (of slow = next of slow and fast = next of next of fast), 
 distance between slow and fast becomes k+1, after two iterations, k+2, and so on. When distance becomes n, 
 they meet because they are moving in a cycle of length n.
*/    
}

void make_cycle(node* head, int pos)   //make a cycle at pos by linnking the last node to the node at pos
{
    node* temp = head;
    node* sub;
    int i = 0;
    while(temp->next!=NULL)
    {
        if(i==(pos-2))
        {
            sub = temp;
        }
        i++;
        temp = temp->next;
    }
    temp->next = sub;
}

node* reversek(node* &head, int k, int allowed)    //reverse node in pair of k, if leftover node < k leave as it is 
{
    node* prev = NULL;
    node* curr = head;
    node* nex;
    int count = 0;
    while(curr!= NULL && count<k && allowed>0)    //reversing the k elements
    {
        nex = curr->next;
        curr->next= prev;
        prev = curr;
        curr = nex;
        count++;
    }
    if(nex!=NULL and allowed>=0)
    {
        allowed--;
        if(allowed==0)    //when we have made groups of k add rest as they are
        {
            allowed--;
            head->next = nex;
        }
        else
            {
                head->next = reversek(nex, k, allowed);    //nex is pointing to next element which is the beginning of the next group
                                                          //and head is the last element of the current group
            }    
    }
    //cout<<"hello";
    return prev;       //previous stores the value which is the last element of the first group and 
                      // now is the head of the reverse k linked list 
    /**
     *  prev =  pre node
        curr = curr node
        next = next node
    after loop:
	    nex will be passed as head which is jholding the first elemnt of the new group
    return prev
	--> at every end prev will be holding the node holding the address of curr element of that loop ehich  is the first element if the group  after 
     */
}

node* head_of_loop(node* head)                     //return head of the loop
{
    //https://www.youtube.com/watch?v=-YiQZi3mLq0&t=198s
    //we keep slow pointer at the place where they had met
    //now we nove fast to head and start moving them forward by 1 step
    //the place where thay again meet is the head of the loop
    node* fast = head;
    node* slow = detect_cycle(head);  
    if(slow!=head)      //there is a loop
    {
        fast = fast->next;
        slow = slow->next;
        if(fast==slow)
        {
            cout<<"head found and  is currently being pointed by fast ";
            return fast;
        }
    }
    return head;
}

void remove_cycle(node* head)             //remove the cycle in the linked list
{
    node* fast = head;
    node* slow = detect_cycle(head);
    if(slow!=head)
    {
        if(fast->next==slow->next)      //at the node in the loop which connects to the head
        {
            slow->next =  NULL;    //making that node point to null will break the loop and make it a normal ll
        }
        fast = fast->next;
        slow = slow->next;
    }
}

void remove_dupplicates(node* head)    //given a sorted link list remove the duplicate elements
{
    node* temp = head;
    while(temp->next!=NULL)
    {
        if(temp->next->data==temp->data)
        {
            temp->next = temp->next->next;
        }
    }
}

void delete_duplicate_in_unsorted_ll(node* &head)     //delete duplicate from  an unsorted linked list
{
	/*unordered_set<int> seen;
    node* curr = head;
    node* prev = NULL;
    while (curr != NULL)
    {
        // If current value is seen before
        if (seen.find(curr->data) != seen.end())
        {
           prev->next = curr->next;
           delete (curr);
        }
        else
        {
           seen.insert(curr->data);
           prev = curr;
        }
        curr = prev->next;
    }*/
}

node* append_last_k_nodes_to_front(node* &head, int k)
{
    node* back_pointer = head;        //the distance between back_pointer and tail of ll is that of k nodes
    node* temp = head;                //so at at the ends back_pointer will be pointing to n-k node 
    int count = 0;
    while(temp->next!=NULL)
    {
        if(count>=k)
        {
            temp = temp->next;
            back_pointer = back_pointer->next;
        }
        else
        {
            temp = temp->next;
            count++;
        }
    }
    temp->next = head;         //connecting the last node to front
    head = back_pointer->next;   //n-k th node's next  will mark starting of k nodes and  thus will become the new head
    back_pointer->next = NULL;   //making the n-k th node the new tail
    return head;
}

void intersect(node*  head1, node* head2, int pos)    //intersect ll2 at position pos of ll1
{
    node* ptr1 = head1;
    node* ptr2 = head2;
    while(ptr2->next!=NULL)
    {
        ptr2 = ptr2->next;
    }
    while(pos)
    {
        ptr1 = ptr1->next;
        pos--; 
    }
    ptr2->next = ptr1;
}

//check intersection point 
int check_intersection(node* head1, node* head2)    //https://www.youtube.com/watch?v=8CACsqPWpHo&list=PLfqMhTWNBTe0b2nM6JHVCnAkhQRGiZMSJ&index=64
{
    int l1 = count(head1);   //length of linked list 1
    int l2 = count(head2);   //length of linked list 2
    int d;
    node* ptr1;
    node* ptr2;
    if(l1>l2)
    {
        d =  l1-l2;
        ptr1 = head1;  //always store the head of longer linked list
        ptr2 = head2;
    }
    else
    {
        d = l2-l1;
        ptr1 = head2;
        ptr2 = head1;
    }
    while(d)
    {
        if(ptr1==NULL)
            return -1;     //NO intersection point
        ptr1 = ptr1->next;
        d--;
    }
    while(ptr1!=NULL and ptr2!=NULL)
    {
        if(ptr1==ptr2)
        {
            return ptr1->data;
        }
        ptr1 = ptr1->next;
        ptr2 = ptr2->next;
    }
    return -1;

}

node* merge_two_sorted(node* head1, node* head2)
{
	node* p1=head1;
	node* p2=head2;
	node* dummy_node = new  node(-1);
    node* p3  = dummy_node;
    while(p1!=NULL and p2!=NULL)
    {
        if(p1->data<=p2->data)
        {
            p3->next = p1;
            p1 = p1->next;
        }
        else
        {
            p3->next = p2;
            p2 = p2->next;
        }
        p3 = p3->next;
    }
    if(p1!=NULL)
    {
        while(p1!=NULL)
        {
            p3->next = p1;
            p1 = p1->next;
            p3 = p3->next;
        }
    }
    else
    {
        while(p2!=NULL)
        {
            p3->next = p2;
            p2 = p2->next;
            p3 = p3->next;
        }
    }
    return dummy_node->next;
}

node* merge_recursive(node* head1,node* head2)
{
    node* result;
    if(head1==NULL)
    {
        return head2;
    }
    if(head2==NULL)
    {
        return head1;
    }
    if(head1->data<=head2->data)
    {
        result = head1;
        result->next = merge_recursive(head1->next, head2);
    }
    else{
        result = head2;
        result->next = merge_recursive(head1, head2->next);
    }
    return result;
}

//move even position elements after odd position elements    https://www.youtube.com/watch?v=TaNfBSbpX_o&list=PLfqMhTWNBTe0b2nM6JHVCnAkhQRGiZMSJ&index=67
void even_after_odd(node* head)
{
    node* odd = head;
    node* even = head->next;
    node* even_start = even;
    while(odd->next!=NULL && even->next!=NULL)
    {
        //cout<<"odd "<<odd->data<<endl;
        odd->next = even->next;
        odd = odd->next;
        //cout<<"even "<<even->data<<endl;
        even->next = odd->next;
        even = even->next;
    }
    odd->next = even_start;
    if(odd->next == NULL)
    {
        even->next = NULL;
    }
}

int main()
{
    node* head = NULL;
    for(int i=1;i<=10;i++)
    {
        append(head, i*10);
    }
    printll(head);
/*  deletenode(head, 10);
    printll(head);
    reverse(head);
    printll(head);*/
/*    int tn = count(head);
    int k;
    cout<<"Enter group size : ";
    cin>>k;
    int allowed = (tn/k);
    node* new_head = reversek(head, k, allowed);
    //cout<<new_head;     */
    //node* new_head = insert_middle(head, 1, 100);
    //printll(new_head);
    //make_cycle(head, 3);
    //detect_cycle(head);
    //printll(append_last_k_nodes_to_front(head, 3));
/*    node* head1 = NULL;
	node* head2 = NULL;
	for(int i=1;i<=10;i++)
	{
		if(i%2)
		{
			append(head1, i);
		}
		else
		{
			append(head2, i);
		}
	}
    printll(head1);
    printll(head2);
    printll(merge_recursive(head1, head2));*/
    even_after_odd(head);
    printll(head);
    return 0;
}