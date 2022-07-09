class Solution {
public:
    int maxScoreSightseeingPair(vector<int>& values) {
        int n = values.size();
        
        int ans = 0, tmp = 0;
        
        for(int i=0; i<n; i++){
            ans = max(ans, values[i]+tmp-i);
            tmp = max(tmp, values[i]+i);
        }
        
        return ans;
    }
};
