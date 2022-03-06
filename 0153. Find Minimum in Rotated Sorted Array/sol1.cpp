class Solution {
public:
    int findMin(vector<int>& nums) {
        int l = 0, r = nums.size()-1;
        
        if(nums[r] > nums[l])
            return nums[l];
        
        while(l<r){
            int mid = l + (r-l)/2;
            if(mid+1 < nums.size() && nums[mid] > nums[mid+1]){
                return nums[mid+1];
            }
            if(mid-1>=0 && nums[mid-1] > nums[mid]){
                return nums[mid];
            }
            
            if(nums[mid] > nums[0]){
                l = mid + 1;
            }
            else{
                r = mid -1;
            }
        }
        return nums[l];
    }
};
