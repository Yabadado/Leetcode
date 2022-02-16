class Solution {
public:
    ListNode* helper(ListNode *head){
        if(!head)
            return nullptr;
        if(!head->next)
            return head;
        
        ListNode *tmp = head->next;
        head->next = helper(tmp->next);
        tmp->next = head;
        return tmp;
    }
    ListNode* swapPairs(ListNode* head) {
        return helper(head);
    }
};
