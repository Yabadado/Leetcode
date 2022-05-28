class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        int ret = n;
        for(auto i=0;i<n; i++){
            ret ^= i;
            ret ^= nums[i];
        }
        return ret;
    }
};
