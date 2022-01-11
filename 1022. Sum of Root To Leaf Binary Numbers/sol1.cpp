class Solution {
public:
    
    void helper(TreeNode *root, int cur , int &ans){
        if(!root)
             return;
        cur = cur*2 + root->val;
        if(!root->left && !root->right){
            ans += cur;
            return;
        }
        helper(root->left, cur, ans);
        helper(root->right, cur, ans);
    }
    
    int sumRootToLeaf(TreeNode* root) {
        int ans = 0;
        helper(root, 0, ans);
        return ans;
    }
};
