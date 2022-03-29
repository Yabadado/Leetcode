class Solution {
public:
    
    int getHeight(TreeNode *root){
        if(!root){
            return 0;
        }
        return max(getHeight(root->left), getHeight(root->right) )+1;
    }
    
    bool isBalanced(TreeNode* root) {
        if(!root)
            return true;
        return abs(getHeight(root->left) - getHeight(root->right)) <=1 && isBalanced(root->left) && isBalanced(root->right);
    }
};
