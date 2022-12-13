class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        vector<vector<int>> dp(n ,vector<int>(n,0));
        //init
        for(int i=0; i<n; i++)
            dp[0][i] = matrix[0][i];
        
        for(int row=1; row<n; row++){
            for(int col=0; col<n; col++){
                int preMin = min({
                        dp[row-1][col-1<0?0:col-1],
                        dp[row-1][col],
                        dp[row-1][col+1==n?n-1:col+1]
                    });
                dp[row][col] = preMin + matrix[row][col];
            }
        }

        int ans = INT_MAX;
        for(int i=0; i<n; i++)
            ans = min(ans, dp[n-1][i]);

        return ans;
    }
};
