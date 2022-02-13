class Solution {
public:
    
    //top-down backtrack
    void helper(vector<int>&nums, vector<vector<int>> &ret, int idx, vector<int> &tmp){
        
        ret.push_back(tmp);
        
        for(int i=idx; i<nums.size(); i++){
            tmp.push_back(nums[i]);
            helper(nums, ret, i+1, tmp);
            tmp.pop_back();
        }
        
    }
    
    vector<vector<int>> subsets(vector<int>& nums) {
        
        vector<vector<int>> ret;
        vector<int> tmp;
        
        helper(nums, ret, 0, tmp);
        
        return ret;
    }
};
