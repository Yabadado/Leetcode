class Solution {
public:
    int totalHammingDistance(vector<int>& nums) {
        vector<int> bitCount(32,0);
        int ans = 0;
        for(int i=0; i<nums.size(); i++)
        {
            int tmp = nums[i];
            for(int j=bitCount.size()-1; j>=0; j--)
            {
                ans += (tmp&1)==1 ? i-bitCount[j] : bitCount[j];
                bitCount[j] += (tmp&1);
                tmp = tmp>>1;
            }        
        }
        return ans;
    }
};
