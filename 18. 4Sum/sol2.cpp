class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        //分類，先SORT
        sort(nums.begin(),nums.end());
        if (target > 0 && target > 4 * nums.back()) return {};
        if (target < 0 && target < 4 * nums.front()) return {};
        
        set<vector<int>> ans;
        
        int n = nums.size();
 
        for (int i = 0; i < n; i++) {   
          for (int j = i + 1; j < n; j++) {                
            for(int k = j + 1; k < n; k++) {
              int t = target - nums[i] - nums[j] - nums[k];
              if (t < nums[k]) break;
              if (!std::binary_search(nums.begin() + k + 1, nums.end(), t)) continue;          
              ans.insert({nums[i], nums[j], nums[k], t});          
            }           
          }
        }
        
        return vector<vector<int>>(begin(ans), end(ans));
    }
};