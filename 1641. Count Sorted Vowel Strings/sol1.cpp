class Solution {
public:
    int countVowelStrings(int n) {
        vector<int> dp1(5,0);
        vector<int> dp2(5,0);
        for(int times=1; times<=n; times++){
            int total = 0;
            for(int i=4; i>=0; i--){
                dp2[i] = dp1[i]==0? 1: dp1[i] + total;
                total=dp2[i];
            }
            swap(dp1, dp2);
        }
        
        int ret = 0;
        for(int i=0; i<5; i++){
            ret += dp1[i];
        }
        return ret;
    }
};
