class Solution {
public:
    
    bool helper(TreeNode* root, TreeNode* subRoot){
        if(!root || !subRoot){
            return root == subRoot;
        }
        
        if(root->val != subRoot->val)
            return false;
        
        return helper(root->left, subRoot->left) && helper(root->right, subRoot->right);
        
    }
    
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if(!root)
            return false;
        
        bool ret = false;
        if(root->val == subRoot->val){
            ret =  helper(root, subRoot);
        }
        
        return isSubtree(root->left, subRoot) || isSubtree(root->right, subRoot) || ret;
    }
};
