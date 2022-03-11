class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        unordered_map<int, int> visit;
        for(int i=0; i<n; i++){
            if(visit[i]==0){
                if(!helper(graph, visit, 1, i)){
                    return false;
                }
            }
        }
        return visit.size()==n;
    }
    
    bool helper(vector<vector<int>>& graph, unordered_map<int, int> &visit, int color, int node){
        if(visit[node]!=0)
            return true;
        visit[node] = color;
        for(int i=0; i<graph[node].size(); i++){
            int next_node = graph[node][i];
            if(visit[next_node]!=0 && visit[next_node] == color)
                return false;
            if(!helper(graph, visit, -color, next_node))
                return false;
        }
        return true;
    }
    
};


