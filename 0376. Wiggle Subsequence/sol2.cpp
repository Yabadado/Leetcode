class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        
        if(nums.size()<2)
            return nums.size();
    
        int prediff = nums[1] - nums[0];
        int count = prediff==0 ? 1 : 2;
        for(int i=2; i<nums.size(); i++){
            int diff = nums[i] - nums[i-1];
            if( (diff>0 && prediff<=0) || (diff<0 && prediff>=0) ){
                count++;
                prediff = diff;
            }
        }
        
        return count;
    }
};
