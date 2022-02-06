class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int ret = 0;
        int i=0;
        for(int n : nums){
            if( i<2 || n > nums[i-2]){
                nums[i] = n;
                i++;
            }
        }
        return i;
    }
};
