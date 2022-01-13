class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        unordered_map<int, vector<int>> childs;
        vector<int> numParent(numCourses, 0);
        
        for(auto req: prerequisites){
            childs[req[1]].push_back(req[0]);
            numParent[req[0]]++;
        }
        
        vector<int> node;
        for(int i = 0; i < numParent.size(); i++){
            if(numParent[i]==0){
                node.push_back(i);
            }
        }
        int cnt = 0;
        
        while(!node.empty()){
            
            vector<int> new_node;
            
            for(int i=0; i<node.size(); i++){
                cnt++;
                for(auto child : childs[node[i]]){
                    if(--numParent[child]==0){
                        new_node.push_back(child);
                    }
                }
            }
            
            node = new_node;
        }
        return cnt==numCourses;
    }
};
