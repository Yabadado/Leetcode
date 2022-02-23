class Solution {
public:
    
    Node* copyNode(Node* node, unordered_map<int, Node*> &mp){
        Node *new_node = new Node(node->val);
        mp[node->val] = new_node;
        for(Node *N: node->neighbors){
            auto iter = mp.find(N->val);
            if(iter==mp.end()){
                new_node->neighbors.push_back(copyNode(N, mp));
            }
            else{
                new_node->neighbors.push_back(iter->second);
            }
        }
        return new_node;
    }
    
    Node* cloneGraph(Node* node) {
        unordered_map<int, Node *>mp;
        if(!node)
            return nullptr;
        
        return copyNode(node, mp);
    }
};
