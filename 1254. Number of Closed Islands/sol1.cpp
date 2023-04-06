class Solution {
public:
    bool validation(vector<vector<int>> &grid, int x, int y){
        if(x==0 || x==grid.size()-1 || y==0 || y==grid[0].size()-1 || grid[x][y]==1){
            return grid[x][y];
        }
        grid[x][y] = 1;
        return validation(grid, x+1, y)&validation(grid, x-1, y)&validation(grid, x, y+1)&validation(grid, x, y-1);
    }
    int closedIsland(vector<vector<int>>& grid) {
        int ans = 0;
        for(int i=0; i<grid.size(); i++){
            for(int j=0; j<grid[0].size(); j++){
                if(grid[i][j]==0){
                    ans += validation(grid, i, j);
                }
            }
        }
        return ans;
    }
};

