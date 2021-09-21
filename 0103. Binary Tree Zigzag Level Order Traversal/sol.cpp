//Time: O(n)
//Space: O(n)
//與102題相同，只在最後處理需反轉的層即可。
class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
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
        for(int i=0; i<ans.size(); i++){
            if(i%2==1)
                reverse(ans[i].begin(),ans[i].end());
        }
        return ans;
    }
};