class Solution {
public:
    
    void helper(TreeNode *root, int &ans){
        
        if(!root)
            return;
        int left = INT_MAX, right = INT_MAX;
        TreeNode *ltmp = root->left;
        TreeNode *rtmp = root->right;
        while(ltmp){
            left = ltmp->val;
            ltmp = ltmp->right;
        }
        while(rtmp){
            right = rtmp->val;
            rtmp = rtmp->left;
        }
        ans = min({ans, abs(left-root->val), abs(right-root->val)});
        
        helper(root->left, ans);
        helper(root->right, ans);
    }
    
    int getMinimumDifference(TreeNode* root) {
        int ans = 10000;
        helper(root, ans);
        return ans;
    }
};