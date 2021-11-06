class Solution {
public:
    
    void backtrack(vector<int> &nums,vector<int> &tmp, int index, vector<vector<int>> &ans){
        
        ans.push_back(tmp);
        
        for(int i=index; i<nums.size(); i++){
            tmp.push_back(nums[i]);
            backtrack(nums, tmp, i+1, ans);
            tmp.pop_back();
        }
        
    }
    
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> tmp;
        backtrack(nums, tmp, 0, ans);
        return ans;
    }
};
