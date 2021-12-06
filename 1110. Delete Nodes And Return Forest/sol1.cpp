class Solution {
public:
    
    void helper(TreeNode* &root, unordered_set<int> &val, vector<TreeNode*> &forest){
        if(!root)
            return;
        
        helper(root->left, val, forest);
        helper(root->right, val, forest);
        
        if(val.find(root->val)!=val.end()){
            if(root->left){
                forest.push_back(root->left); 
            }
            if(root->right){
                forest.push_back(root->right);
            }
            root = nullptr;
        }
    }
         
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        
        vector<TreeNode*> forest;
        unordered_set<int> p;
    
        for(int i: to_delete)
            p.insert(i);
        
        helper(root, p, forest);
        
        if(root)
            forest.push_back(root);

        return forest;
    }
    
};