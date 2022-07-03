class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        
        if(nums.size()<2)
            return nums.size();
        
        vector<int> ret={nums[0]};
    
        bool inc;
        int i = 0;
        for(i=1; i<nums.size(); i++){
            if(nums[i]!=nums[0]){
                inc = nums[0]<nums[i] ? true : false;
                break;
            }
        }
        
        for(; i<nums.size(); i++){
            if( (inc&&ret.back()>nums[i]) || (!inc&&ret.back()<nums[i]) ){
                ret.pop_back();
                ret.push_back(nums[i]);
            }
            else if( (inc&&ret.back()<nums[i]) || (!inc&&ret.back()>nums[i]) ){
                inc = !inc;
                ret.push_back(nums[i]);
            }
        }
        
        return ret.size();
    }
};
