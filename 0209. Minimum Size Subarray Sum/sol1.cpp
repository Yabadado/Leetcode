class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n = nums.size();
        int left = 0;
        int right = 0;
        int sum = 0; 
        int ans =INT_MAX; 
        while(right < n)
        {
            sum += nums[right];
            if(sum >= target)
            {
                while(sum >= target)
                {
                   sum -= nums[left];
                    left++;
                }
                ans = min(ans,right-left+2);
            }
            right++;
        }
        if(ans == INT_MAX) return 0;

        return ans;
    }
};
