class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());\
        int i = 0, j=nums.size()-1;
        int ans = 0;
        
        while(i<j){
            int cur = nums[i]+nums[j];
            if(cur == k){
                ans++;
                i++;
                j--;
            }
            else if(cur > k){
                j--;
            }
            else{
                i++;
            }
        }
        return ans;
    }
};
