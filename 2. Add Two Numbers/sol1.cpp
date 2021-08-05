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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *now = new ListNode;
        ListNode *ans = now;
        int carry = 0;
        int val = 0;
        
        while(l1 || l2){
            ListNode* cur = new ListNode();
            
            if(l1 && l2 ){
                val = l1->val + l2->val + carry;    
            }
            else if(l1){
                val = l1->val + carry;
            }
            else if(l2){
                val = l2->val + carry;
            }
            if(val >= 10){
                val %= 10;
                carry = 1;
            }
            else{
                carry = 0;
            }
            
            cur->val = val;
            now->next = cur;
            now = now->next;
            
            if(l1)
                l1 = l1->next;
            if(l2)
                l2 = l2->next;
        }
        
        // if there is carry
        if(carry){
            ListNode *tmp = new ListNode(carry);
            now->next = tmp;
        }
        return ans->next;
    }
};