class Solution {
public:
    int countOrders(int n) {
        vector<long long> dp(n+1, 0);
        int M = 1e9+7;
        dp[0] = 1;
        for(int i=1; i<=n; i++){
            long long tmp = dp[i-1]*i*(2*i-1);
            dp[i] = (int)(tmp % M);
        }
        return dp[n];
    }
};
