class Solution {
public:
    bool validTree(int n, vector<vector<int>>& edges) {
        unordered_map<int, vector<int>> graph;
        vector<bool> visit(n, false);
        
        for(auto &e: edges){
            graph[e[0]].push_back(e[1]);
            graph[e[1]].push_back(e[0]);
        }
        
        if(!dfs(graph, 0, 0, visit)){
            return false;   
        }
        //檢查是否有額外獨立(沒有跟0相連的)的node
        for(auto F:visit){
            if(!F)
                return false;
        }
        return true;
    }
    
    bool dfs(unordered_map<int, vector<int>> &graph, int src, int cur_node, vector<bool> &visit){
        
        if(visit[cur_node])
            return false;
        
        visit[cur_node] = true;
        
        for(auto &n:graph[cur_node]){
            if(n!=src){
                if(!dfs(graph, cur_node, n, visit)){
                    return false;
                }
            }
        }
        return true;
    }
};
