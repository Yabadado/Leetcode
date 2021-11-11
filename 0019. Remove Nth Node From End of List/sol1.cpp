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
    
    int getLen(ListNode* root){
        int len = 0;
        while(root){
            len++;
            root = root->next;
        }
        return len;
    }
    
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        
        int len = getLen(head);
        int cnt = len-n;
        
        ListNode* root = head;
        ListNode* pre = nullptr;
        ListNode* tmp = head;        
        
        if(cnt==0){
            if(!head->next)
                return NULL;
            head = head->next;
            return head;
        }
        
        
        while(cnt--){
            tmp = head->next;
            pre = head;
            head = head->next;
        }
        
        pre->next = tmp->next;
        
        return root;
    }
};
