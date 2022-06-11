class Solution {
public:
    int maxRotateFunction(vector<int>& nums) {
        int sum = 0, cur=0;
        for(int i=0; i<nums.size(); i++){
            sum+=nums[i];
            cur+=i*nums[i];
        }
        int n = nums.size();
        int ret = cur;
        for(int i=1; i<nums.size(); i++){
            cur = cur-sum+n*nums[i-1];
            ret = max(ret, cur);
        }
        return ret;
    }
};

/*
[a, b, c, d]

0 1 2 3 -> 0a + 1b + 2c + 3d
           3a + 0b + 1c + 2d
           2a + 3b + 0c + 1d
           1a + 2b + 3c + 0d
*/
