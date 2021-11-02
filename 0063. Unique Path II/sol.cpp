//Time: O(m*n)
//Sapce: O(m*n)

class Solution {
public:
    
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int ans = 0;
        int m = obstacleGrid.size(), n = obstacleGrid[0].size();
        vector<vector<int>> dp(m, vector<int>(n,0));
        
        dp[0][0] = obstacleGrid[0][0]==1 ? 0 : 1;
        
        for(int i=1; i<m; i++){
            obstacleGrid[i][0]==0 ? dp[i][0] = dp[i-1][0] : dp[i][0] = 0;
        }
        for(int j=1; j<n; j++){
            obstacleGrid[0][j]==0 ? dp[0][j] = dp[0][j-1] : dp[0][j] = 0;
        }
        
        for(int i=1; i<m; i++){
            for(int j=1; j<n; j++){
                obstacleGrid[i][j]==0 ? dp[i][j] = dp[i-1][j] + dp[i][j-1] : dp[i][j] = 0;
            }
        }
        
        return dp[m-1][n-1];
    }
};
