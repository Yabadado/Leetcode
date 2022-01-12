/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
#define NP pair<int,int>
class Solution {
public:
    
    NP helper(TreeNode* root){
        if(!root)
            return {0,0};
        
        int left = 0, right = 0;
        NP lp = helper(root->left);
        NP rp = helper(root->right);
        
        int maxLR = max(lp.first, lp.second) + max(rp.first, rp.second);    //只取左右的話要找最大。
        int addSelf = root->val + lp.first + rp.first;                      //否則有包含自己就只能選前個節點只有左右的。
        
        return make_pair(maxLR, addSelf);
    }
    
    int rob(TreeNode* root) {
        NP s = helper(root);
        return max(s.first, s.second);
    }
};


/*
state machine?
8:02~8:30
rob <-> idle
以buttom-up回來，並只紀錄前面節點的最大值，但要記錄包含該節點(有搶)，不包含該節點(沒搶)
帶入下次遞迴。

*/