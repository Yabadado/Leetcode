class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int tmp = nums[0];
        int sum = nums[0];
        
        for(int i=1;i<nums.size();i++)
        {
            tmp+=nums[i];
            if(tmp>sum) 
                sum = tmp;
            if(nums[i]>tmp){
                tmp = nums[i];
                if(tmp>sum) sum = tmp;
            }
        }
        return sum;
    }
};