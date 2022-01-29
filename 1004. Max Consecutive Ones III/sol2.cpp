class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int cur_zero = 0;
        int i=0, j=0;
        int ans = 0;
        
        while(j<nums.size()){
            
            if(nums[j]==0){
                cur_zero++;
            }
            while(cur_zero>k){
                if(nums[i]==0)
                    cur_zero--;
                i++;
            }
            ans = max(ans, j-i+1);
            j++;
        }
        ans = max(j-i, ans);
        
        return ans;
    }
};
