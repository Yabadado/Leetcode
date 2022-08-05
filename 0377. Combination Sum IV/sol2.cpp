class Solution {
public:
    
    unordered_map<int, int> mp; //<num, counter>
    
    int helper(vector<int> &nums, int target){
        if(target < 0)
            return 0;
        if(target == 0)
            return 1;
        
        if(mp.find(target)!=mp.end())
            return mp[target];
        
        int ret = 0;
        
        for(int i=0; i<nums.size(); i++){
            ret += helper(nums, target-nums[i]);
        }
        
        mp[target] += ret;
        
        return ret;
    }
    
    int combinationSum4(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        return helper(nums, target);
    }
};


/*
hash map -> (num , counter)
 
recursion:
    base case
        num>target
    
    mp[num] +=1
    
    if(target-nums[idx]):
        return mp[nums[idx]]
    
    int ret = 0;
    for(idx=0~n):
        ret += resursion(num+nums[idx]);
    
    return ret;

*/
