class Solution {
public:
    bool helper(TreeNode* root, int k, unordered_set<int> &s){
        if(!root)
            return false;
        if(s.find(k-root->val)!=s.end())
            return true;
        s.insert(root->val);
        return helper(root->left, k, s) || helper(root->right, k, s);
    }
    bool findTarget(TreeNode* root, int k) {
        unordered_set<int> s;
        return helper(root, k , s);
    }
};
