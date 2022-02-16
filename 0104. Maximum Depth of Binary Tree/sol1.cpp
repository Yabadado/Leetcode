/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    void top_down(TreeNode *root, int &depth, int tmp){
        if(!root){
            depth = max(depth, tmp);
            return;
        }
        top_down(root->left, depth, tmp+1);
        top_down(root->right, depth, tmp+1);
    }
    
    int maxDepth(TreeNode* root) {
        int ret = 0;
        top_down(root, ret, 0);
        return ret;
    }
};
