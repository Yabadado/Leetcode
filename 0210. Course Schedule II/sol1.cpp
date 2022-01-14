class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        unordered_map<int, vector<int> > graph;
        vector<int> degree(numCourses, 0);
                      
        for(auto req: prerequisites){
            graph[req[1]].push_back(req[0]);
            degree[req[0]]++;
        }
        
        queue<int> node;
        for(int i=0; i<degree.size(); i++){
            if(degree[i]==0){
                node.push(i);
            }
        }
        vector<int> order;
        int cnt = 0;
        while(!node.empty()){
            
            int course = node.front();
            node.pop();
            order.push_back(course);
            cnt++;
            
            for(auto i: graph[course]){
                if(--degree[i]==0){
                    node.push(i);
                }
            }
        }
        
        return cnt==numCourses ? order : vector<int>();
        
    }
};
