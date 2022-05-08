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
class Solution {
public:
    void helper(TreeNode *root, int minVal, int maxVal, int &ans){
        if(!root)
            return;
        
        ans = max({ans, abs(minVal-root->val), abs(maxVal-root->val)});

        minVal = min(minVal, root->val);
        maxVal = max(maxVal, root->val);
        
        helper(root->left, minVal, maxVal, ans);
        helper(root->right, minVal, maxVal, ans);
        
    }
    int maxAncestorDiff(TreeNode* root) {
        int ans = 0;
        
        if(!root)
            return ans;
        
        helper(root, root->val, root->val, ans);
        
        return ans;
    }
};
