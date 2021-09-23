//Time:O(n)
//Space:O(n)
class Solution {
public:
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>> ans;
        if(!root)
            return {};
        
        queue<TreeNode*> node;
        node.push(root);
        
        while(!node.empty()){
            vector<int> layer;
            queue<TreeNode*> tmp;
            while(!node.empty()){
                TreeNode *n = node.front(); node.pop();
                layer.push_back(n->val);
                if(n->left) tmp.push(n->left);
                if(n->right) tmp.push(n->right);
            }           
            ans.push_back(layer);
            node = tmp;
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};