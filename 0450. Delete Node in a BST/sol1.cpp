class Solution {
public:
    
    TreeNode* findConnectPoint(TreeNode* root, int dir){
        
        if(!root)
            return root;
        TreeNode *pre;
        while(root){
            pre = root;
            if(dir==0){   
                root = root->left;
            }
            else{
                root = root->right;
            }
        }
        return pre;
    }
    
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(!root){
            return root;
        }
        if(root->val==key){
            if(root->left){
                TreeNode *tmp = findConnectPoint(root->left, 1);
                tmp->right = root->right;
                root = root->left;
            }
            else if(root->right){
                TreeNode *tmp = findConnectPoint(root->right, 0);
                tmp->left = root->left;
                root = root->right;
            }
            else{
                return nullptr;
            }
            return root;
        }
        root->left = deleteNode(root->left, key);
        root->right = deleteNode(root->right, key);
            
        return root;
    }
};
