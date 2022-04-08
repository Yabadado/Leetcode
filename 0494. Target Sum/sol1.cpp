class Solution {
public:
    unordered_map<int, unordered_map<int, int>> memo;
    int helper(vector<int> &nums, int idx, int left){
        if(idx==nums.size()){
            if(left==0)
                return 1;
            else
                return 0;
        }
        
        if(memo[idx].find(left)!=memo[idx].end()){
            return memo[idx][left];
        }
        
        int l = helper(nums, idx+1, left+nums[idx]);
        int r = helper(nums, idx+1, left-nums[idx]);
        memo[idx][left] = l+r;
        return memo[idx][left];
    }
    
    int findTargetSumWays(vector<int>& nums, int target) {
        return helper(nums, 0, target);
    }
};
