//Time: O(n)
//Space: O(n)
class Solution {
public:
    //先知道tree的深度。
    //vector從後面填回來

    int getDepth(TreeNode* root){
        if(!root) return 0;        
        return max(getDepth(root->left), getDepth(root->right))+1;
    }
    
    void getOrder(vector<vector<int>>&ans, TreeNode* root, int depth){
        if(!root) return;
        ans[depth].push_back(root->val);
        getOrder(ans, root->left, depth-1);
        getOrder(ans, root->right, depth-1);
    }
    
    
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        int depth = getDepth(root);
        vector<vector<int>> ans(depth);
        getOrder(ans, root, depth-1);
        return ans;
    }
};