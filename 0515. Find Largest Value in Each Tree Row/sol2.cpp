class Solution {
public:
    vector<int> largestValues(TreeNode* root) {
        vector<int> ret;
        queue<TreeNode *> q;
        if(!root)
            return {};
        
        q.push(root);
        
        while(!q.empty()){
            int size = q.size();
            int maxVal = INT_MIN;
            while(size--){
                TreeNode *node = q.front();
                maxVal = max(maxVal, node->val);
                q.pop();
                if(node->left)
                    q.push(node->left);
                if(node->right)
                    q.push(node->right);
            }
            ret.push_back(maxVal);
        }
        return ret;
    }
};
