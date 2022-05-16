class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        //BFS
        int n = grid.size();
        
        if(grid[0][0] || grid[n-1][n-1])
            return -1;
        
        queue<pair<int, int>> q; q.push({0,0});
        queue<pair<int, int>> next_q;
        int layer = 1;
        
        while(!q.empty()){
            while(!q.empty()){
                auto [x, y] = q.front(); q.pop();
                if(x<0 || x==n || y<0 || y==n || grid[x][y]==1)
                    continue;
                
                grid[x][y] = 1;
                if(x==n-1 && y==n-1)
                    return layer;
                
                //find all possible
                for(int dx=-1;dx<=1; dx++){
                    for(int dy=-1; dy<=1; dy++){
                        if(dx!=0 || dy!=0){
                            next_q.push({x+dx,y+dy});
                        }
                    }
                }
            }
            swap(q, next_q);
            layer++;
        }
        return -1;
    }
};
