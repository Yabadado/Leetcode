class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n = nums.size();
        unordered_map<int, int> mp; 
        int sum = 0;
        int ret = INT_MAX;
        for(int i=0; i<n; i++){
            sum += nums[i];
            if(mp.find(sum - target)!=mp.end()){
                ret = min(ret, i-mp[sum-target]);
            }
            mp[sum] = i;
        }
        return ret==INT_MAX ? 0 : ret;
    }
};
