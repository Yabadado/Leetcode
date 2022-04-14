class Solution {
public:
    TreeNode* pre = nullptr;
    bool isValidBST(TreeNode* root) {
        bool l = true, r =true;
        
        if(root->left)
            l = isValidBST(root->left);
        
        if(pre && pre->val >= root->val){
            return false;
        }
        pre = root;
        
        if(root->right)
            r = isValidBST(root->right);
        
        return l && r;
    }
};
