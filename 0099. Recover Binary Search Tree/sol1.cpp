class Solution {
public:
    
    void helper(TreeNode *root, vector<int> &order){
        if(!root)
            return;
        helper(root->left, order);
        order.push_back(root->val);
        helper(root->right, order);
    }
    
    void rebuild(TreeNode* root, vector<int> &order, int &idx){
        if(!root)
            return;
        rebuild(root->left, order, idx);
        root->val = order[idx++];
        rebuild(root->right, order, idx);
    }
    
    void recoverTree(TreeNode* root) {
        vector<int> order;
        int i=0;
        helper(root, order);
        sort(order.begin(), order.end());
        rebuild(root, order, i);
    }
};
