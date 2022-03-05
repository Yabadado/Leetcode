class Solution {
public:
    int shortestBridge(vector<vector<int>>& grid) {
        queue<pair<int,int>> q;
        for(int i=0; i<grid.size() && q.empty(); i++){
            for(int j=0; j<grid[i].size() && q.empty(); j++){
                if(grid[i][j]==1){
                    dfs(grid, i, j, q);
                }
            }
        }
        
        int layer = 0;
        vector<vector<int>> dir = {{1,0}, {0,1}, {0, -1}};
        
        while(!q.empty()){
            queue<pair<int,int>> new_q;
            while(!q.empty()){
                auto [x, y] = q.front(); q.pop();
                for(int i=0; i<3; i++){
                    int dx = x+dir[i][0], dy = y+dir[i][1];
                    if(dx<0 || dx== grid.size() || dy<0 || dy==grid[0].size() || grid[dx][dy]==2)
                        continue;
                    if(grid[dx][dy]==1)
                        return layer;
                    grid[dx][dy] = 2;
                    new_q.push({dx, dy});
                }
            }
            q = new_q;
            layer++;
        }
        return layer;
    }
    
    void dfs(vector<vector<int>> &grid, int x, int y, queue<pair<int,int>> &q){
        if(x<0 || x== grid.size() || y<0 || y==grid[0].size() || grid[x][y]!=1){
            return;
        }
        q.push({x,y});
        grid[x][y] = 2;
        
        dfs(grid, x+1, y, q);
        dfs(grid, x-1, y, q);
        dfs(grid, x, y+1, q);
        dfs(grid, x, y-1, q);
    }
    
};
