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
    
    ListNode *helper(ListNode* l1, ListNode* l2, int carry){
        if(!l1){
            l1 = new ListNode(0);
        }
        if(!l2){
            l2 = new ListNode(0);
        }
        
        carry += (l1->val + l2->val);
        l1-> val = carry%10;
        carry/=10;
        
        if(l1->next || l2->next || carry)
            l1->next = helper(l1->next, l2->next, carry);
        
        return l1;
        
    }
    
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        return helper(l1, l2, 0);
    }
};
