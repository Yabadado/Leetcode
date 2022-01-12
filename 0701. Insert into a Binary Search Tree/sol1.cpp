class Solution {
public:
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        
        if(!root){
            root = new TreeNode(val);
            return root;
        }
        
        TreeNode *pre = nullptr;
        TreeNode *tmp = root;
        while(tmp){
            pre = tmp;
            if(tmp->val > val){
                tmp = tmp->left;
            }
            else{
                tmp = tmp->right;
            }
            if(!tmp){
                tmp = new TreeNode(val);
                if(pre->val > val){
                    pre->left = tmp;
                }
                else{
                    pre->right = tmp;
                }
                break;
            }
        }
        return root;
    }
};
