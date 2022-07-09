class Solution {
public:
    int maxScoreSightseeingPair(vector<int>& values) {
        int n = values.size();
        vector<int> nextMax(n+1, INT_MIN);
        
        for(int i=n-1; i>=0; i--){
            nextMax[i] = max(nextMax[i+1], values[i] - i);
        }

        int ret = 0;
        for(int i=0; i<n-1; i++){
            ret = max(ret, values[i]+i+nextMax[i+1]);
        }
        
        return ret;
    }
};
