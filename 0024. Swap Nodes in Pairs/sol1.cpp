class Solution {
public:
    
    ListNode* recur(ListNode *head){
        if(!head or !head->next)
            return head;
        
        ListNode *first = head;
        ListNode *second = head->next;
        ListNode *tmp = second->next;
        
        second->next = first;
        first->next = recur(tmp);
        
        return second;
    }
    
    
    ListNode* swapPairs(ListNode* head) {
        
        if(!head or !head->next)
            return head;
        
        return recur(head);
    }
};
