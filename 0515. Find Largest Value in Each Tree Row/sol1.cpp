class Solution {
public:
    void helper(TreeNode* root, int depth, vector<int> &ret){
        if(!root)
            return;
        if(depth>=ret.size()){
            ret.push_back(root->val);
        }
        else{
            ret[depth] = max(root->val, ret[depth]);
        }
        
        helper(root->left, depth+1, ret);
        helper(root->right, depth+1, ret);
    }
    vector<int> largestValues(TreeNode* root) {
        vector<int> ret;
        helper(root, 0, ret);
        return ret;
    }
};
