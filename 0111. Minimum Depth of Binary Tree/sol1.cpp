//Time: O(n)
//Space: O(n)
//BFS->掃到該點為葉節點(leaf)就回傳。
class Solution {
public:
    int minDepth(TreeNode* root) {
        vector<TreeNode*> node;
        if(!root)
            return 0;
        
        node.push_back(root);
        
        int layer=0;
        
        while(!node.empty()){
            vector<TreeNode*> next_node;
            layer++;
            for(TreeNode* n : node){
                if(!n->left && !n->right)
                    return layer++;
                if(n->left)
                    next_node.push_back(n->left);
                if(n->right)
                    next_node.push_back(n->right);
            }
            node = next_node;            
        }
        return layer;
    }
};