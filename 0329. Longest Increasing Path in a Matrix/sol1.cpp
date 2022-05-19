class Solution {
public:
    
    vector<pair<int,int>> dir = { {-1,0}, {1,0}, {0,-1}, {0,1} };
    vector<vector<int>> memo;
    
    int dfs(vector<vector<int>>&matrix, int pre, int x, int y){
        
        if(x<0 || x>=matrix.size() || y<0 || y>=matrix[0].size() || matrix[x][y] <= pre){
            return 0;
        }
        
        if(memo[x][y]!=-1)
            return memo[x][y];
        
        int ret = 0;
        for(auto [dx, dy]:dir){
            ret = max(ret, dfs(matrix, matrix[x][y], x+dx, y+dy)+1);
        }
        memo[x][y] = ret;
        
        return ret;
    }
    
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        
        int m = matrix.size();
        int n = matrix[0].size();

        memo = vector<vector<int>>(m, vector<int>(n, -1));
        
        int ret = 0;
        for(int i=0;i<matrix.size(); i++){
            for(int j=0;j<matrix[0].size(); j++){
                ret = max(ret, dfs(matrix, INT_MIN, i, j));
            }
        }
        return ret;
    }
};
