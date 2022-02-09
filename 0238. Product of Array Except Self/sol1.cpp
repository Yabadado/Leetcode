//Time: O(n)
//Space: O(n)
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {     
        int n = nums.size();
        vector<int> dp(n, 1);
	//left = prefix product , right = suffix product        
        int left = 1, right = 1;
        for(int i=0; i<n; i++){
            dp[i] *= left;
            dp[n-i-1] *= right;
            
            left *= nums[i];
            right *= nums[n-i-1];
        }
        return dp;
    }
};


