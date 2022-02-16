class Solution {
public:
    int bottom_up(TreeNode *root, int cur){
        if(!root)
            return cur;
        return max(bottom_up(root->left, cur+1), bottom_up(root->right, cur+1));
    }
    
    int maxDepth(TreeNode* root) {
        return bottom_up(root, 0);
    }
};
