class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        int i=0 , n = nums.size();
        vector<string> ret;
        while(i<n){
            ret.push_back(to_string(nums[i]));
            bool cnt = false; 
            while(i+1<n && nums[i]==nums[i+1]-1){
                cnt = true;
                i++;
            }
            if(cnt){
                ret.back() += "->" + to_string(nums[i]);
            } 
            i++;
        }
        return ret;
    }
};
