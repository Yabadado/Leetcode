/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        
        ListNode *fast=head, *slow=head, *pre=nullptr;
        
        for(int i=0; i<n && fast!=nullptr; i++){
            fast = fast->next;
        }
        while(fast!=nullptr){
            pre = slow;
            slow = slow->next;
            fast = fast->next;
        }
        
        if(pre == nullptr){
            return slow->next;
        }
        
        pre->next = slow->next;
        
        return head;
    }
};

