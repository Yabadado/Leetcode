class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        set<vector<int>> ans;
        sort(nums.begin(), nums.end());
        int n = nums.size();
        for(int i=0;i<n-3;i++){
            for(int j=i+1;j<n-2;j++){
                for(int k=j+1; k<n-1;k++){
                    for(int l=k+1; l<n; l++){
                        if(nums[i]+nums[j]+nums[k]+nums[l]==target)
                            ans.insert({nums[i],nums[j],nums[k],nums[l]});
                    }
                }
            }
        }
        vector<vector<int>> ret(ans.begin(), ans.end());
        return ret;
    }
};