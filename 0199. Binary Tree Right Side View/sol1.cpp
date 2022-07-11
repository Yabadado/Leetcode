class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        vector<TreeNode* > layer;
        if(root) layer.push_back(root);
        
        vector<int> ret;
        
        while(!layer.empty()){
            ret.push_back(layer.back()->val);
            vector<TreeNode*> next_layer;
            for(int i=0; i<layer.size(); i++){
                TreeNode *cur = layer[i];
                if(cur->left) 
                    next_layer.push_back(cur->left);
                if(cur->right)
                    next_layer.push_back(cur->right);
            }
            swap(layer, next_layer);
        }
        return ret;
    }
};
