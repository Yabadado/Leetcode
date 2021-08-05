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
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(head==NULL || k ==1)  return head;
        ListNode *ret = new ListNode(0);
        ret->next = head;
        
        ListNode *cur = ret;
        ListNode *next = ret;
        ListNode *front = ret; 
        int cnt = 0;
        
        while(cur->next != NULL){
            cur = cur->next;
            cnt++;
        }
        while(cnt>=k){
            cur = front->next;
            next = cur->next;
            for(int i=1;i<k;i++){
                cur->next = next->next;
                next->next = front->next;
                front->next = next;
                next = cur->next;
            }
            front = cur;
            cnt-=k;
        }
        return ret->next;
    }
};