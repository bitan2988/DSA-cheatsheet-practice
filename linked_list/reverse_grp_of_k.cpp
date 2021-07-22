class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        
        if(head==NULL || k==1)
            return head;
        
        ListNode* dummy = new ListNode(-1);
        dummy->next = head;
        
        ListNode* curr = dummy;
        ListNode* nex = dummy;
        ListNode* pre = dummy;
        
        // Count the length of the linked list
        int cnt = 0;
        while(curr->next != NULL){
            curr = curr->next;
            cnt++;
        }
        
        
        while(cnt >= k){
            curr = pre->next;
            nex = curr->next;
            
            for(int i=1; i<k; i++){
                curr->next = nex->next;
                nex->next = pre->next;
                pre->next = nex;
                nex = curr->next;
            }
            
            pre = curr;
            cnt -= k;
        }
        
        return dummy->next;
    }
};
