//Time : O(n)
//Space : O(n)
//紀錄目前走過的該層節點，並新增次層節點進queue
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        queue<TreeNode*> q;
       
        if(root){
            q.push(root);
        }
        
        vector<vector<int>> ans;
        
        while(!q.empty()){
            queue<TreeNode*> new_q;   // next layer node.
            vector<int> res;          // this layer result.
            while(!q.empty()){
                TreeNode *tmp = q.front();
                q.pop();
                res.push_back(tmp->val);
                if(tmp->left)
                    new_q.push(tmp->left);
                if(tmp->right)
                    new_q.push(tmp->right);
            }
            ans.push_back(res);
            q = new_q;
        }
        return ans;
    }
};