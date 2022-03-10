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
    ListNode* rotateRight(ListNode* head, int k) {
        
        if(!head || !head->next)
            return head;
        ListNode *pre = nullptr;
        ListNode *tmp = head;
        int len = 1;
        
        while(tmp->next){
            tmp = tmp->next;
            len++;
        }
        pre = tmp;
        tmp->next = head;
        
        int cnt = k > len ? len-(k%len) : (len-k);
        
        tmp = head;        
        while(cnt--){
            pre = head;
            head = head->next;
        }
        pre->next = nullptr;
        return head;
    }
};
