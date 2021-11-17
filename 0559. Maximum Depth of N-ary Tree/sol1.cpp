class Solution {
public:
    
    int maxDepth(Node* root) {
        
        int layer = 0;
        vector<Node*> node;
        
        if(root)
            node.push_back(root);
        
        while(node.size()){
            
            vector<Node*> new_node;
            
            for(auto n: node){
                for(auto child: n->children){
                    if(child)
                        new_node.push_back(child);
                }
            }
            
            node = new_node;
            layer++;
        }
        return layer;
    }
};