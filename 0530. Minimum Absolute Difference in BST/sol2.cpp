class Solution {
public:
    
    int curNum = -1;
    
    void inorder(TreeNode *root, int &ans){
        if(!root)
            return;
        
        inorder(root->left, ans);
        
        if(curNum > -1){
            ans = min(ans, root->val - curNum);
        }
        curNum = root->val;
        inorder(root->right, ans);
    }
    
    int getMinimumDifference(TreeNode* root) {
        int ans = 10000;
        inorder(root, ans);
        return ans;
    }
};