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
    
    void reorderList(ListNode* head) {
        ListNode *slow = head, *fast = head->next;
        while(fast && fast->next){
            slow = slow->next;
            fast = fast->next->next;
        }
        
        fast = slow->next;
        slow->next = nullptr;
        slow = head;
        
        //reverse fast list
        ListNode *pre = nullptr;
        while(fast){
            ListNode *cur = fast->next;
            fast->next = pre;
            pre = fast;
            fast = cur;
        }
        
        ListNode *l1 = head;
        ListNode *l2 = pre;
        
        
        while(l1 && l2){
            ListNode* nl1 = l1->next;
            ListNode* nl2 = l2->next;
            
            l1->next = l2;
            l1 = nl1;
            
            l2->next = nl1;
            l2 = nl2;
            
        }
        
        
    }
};

/*


*/
