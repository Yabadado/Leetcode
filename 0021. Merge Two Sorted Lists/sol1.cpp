class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if(!list1)
            return list2;
        if(!list2)
            return list1;
        
        ListNode *ret;
        
        if(list1->val < list2->val){
            ret = list1;
            list1->next = mergeTwoLists(list1->next, list2);
        }
        else{
            ret = list2;
            list2->next = mergeTwoLists(list1, list2->next);
        }
        return ret;
    }
};
