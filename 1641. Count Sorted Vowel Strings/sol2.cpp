class Solution {
public:
    int countVowelStrings(int n) {
        vector<int> dp(5,1);
        
        for(int i = 2; i <=n ; i++){
            dp[3]+=dp[4];
            dp[2]+=dp[3];
            dp[1]+=dp[2];
            dp[0]+=dp[1];
        }
        
        int ans = dp[0]+dp[1]+dp[2]+dp[3]+dp[4];
        
        return ans;
        
  
    }
};
