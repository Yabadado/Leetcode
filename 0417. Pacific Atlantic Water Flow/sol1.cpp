class Solution {
public:
    vector<pair<int,int>> dir = {{1,0},{-1,0},{0,1},{0,-1}};
    set<pair<int,int>> BFS(queue<pair<int,int>> &q, vector<vector<int>> &mat, vector<vector<bool>> visited){
        set<pair<int,int>> ret;
        queue<pair<int,int>> new_q;
        while(!q.empty()){
            while(!q.empty()){
                auto[x, y] = q.front(); q.pop();
                ret.insert({x,y});
                for(auto [dx, dy]: dir){
                    if(x+dx>=0 && x+dx<mat.size() && y+dy>=0 && y+dy<mat[0].size() && mat[x][y] <= mat[x+dx][y+dy] && !visited[x+dx][y+dy]){
                        visited[x+dx][y+dy] = true;
                        new_q.push({x+dx, y+dy});
                    }
                }
            }
            swap(q, new_q);
        }
        return ret;
    }
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        
        int m = heights.size();
        int n = heights[0].size();
        vector<vector<bool>> visited(m, vector<bool>(n, false));

        queue<pair<int, int>>q;
        for(int i=0; i<m; i++)
            q.push({i, 0});
        for(int j=1; j<n; j++)
            q.push({0, j});
        
        auto s1 = BFS(q, heights, visited);
        
        for(int i=m-1; i>=0; i--)
            q.push({i, n-1});
        for(int j=n-2; j>=0; j--)
            q.push({m-1, j});
        
        visited = vector<vector<bool>>(m, vector<bool>(n, false));
        auto s2 = BFS(q, heights, visited);
        
        vector<vector<int>>ret;
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(s1.count({i,j}) && s2.count({i,j}))
                    ret.push_back({i,j});
            }
        }
        return ret;
    }
};
