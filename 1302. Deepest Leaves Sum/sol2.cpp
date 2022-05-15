class Solution {
public:
    void helper(TreeNode* root, pair<int,int> &sum, int depth){
        if(!root)
            return;
        
        if(depth==sum.first)
            sum.second+=root->val;
        
        if(depth > sum.first){
            sum.first = max(depth, sum.first);
            sum.second = root->val;
        }
        
        helper(root->left, sum, depth+1);
        helper(root->right, sum, depth+1);
    }
    int deepestLeavesSum(TreeNode* root) {
        pair<int, int> sum = {0,0};
        helper(root, sum, 0);
        return sum.second;
    }
};
