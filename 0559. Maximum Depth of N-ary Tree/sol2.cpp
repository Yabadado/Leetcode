class Solution {
public:
    
    int getDepth(Node* root){
        
        if(!root)
            return 0;
        int ret = 0;
        for(auto child: root->children){
            ret = max(ret, getDepth(child));
        }
        
        return ret+1;
    }
    
    
    int maxDepth(Node* root) {
        return getDepth(root);
    }
};