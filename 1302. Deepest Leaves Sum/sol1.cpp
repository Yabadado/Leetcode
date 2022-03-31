class Solution {
public:
    pair<int, int> helper(TreeNode *root, int d){
        
        if(!root){
            return {0, -1};
        }
        
        if(!root->left && !root->right){
            return {root->val, d};
        }
        auto [l, dl] = helper(root->left, d+1);
        auto [r, dr] = helper(root->right, d+1);
        
        if(dl > dr){
            return {l, dl};
        }
        else if(dr > dl){
            return {r, dr};
        }
        else{
            return {l+r, dl};
        }
    }
    int deepestLeavesSum(TreeNode* root) {
        return helper(root, 1).first;
    }
};
