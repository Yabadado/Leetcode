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

//Time Complexity:O(n) -> n = len(linked list)
//Space Complexity: O(1)

class Solution {
public:
    
    ListNode* removeElements(ListNode* head, int val) {
        
        if(!head)
            return nullptr;
        
        head->next = removeElements(head->next, val);
        
        if(head->val==val)
            return head->next;
        
        return head;
    }
};


/*
recursion
dummy node hold node
return dummy->next;
*/