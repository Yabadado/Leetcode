class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        vector<int> dp(n, 0);
        for(int i=n-1; i>=0; i--){
            
            for(int j=0; j<triangle[i].size()-1; j++){
                dp[j] = min(triangle[i][j]+dp[j], triangle[i][j+1]+dp[j+1]);
            }
        }
        return dp[0] + triangle[0][0];
    }
};
