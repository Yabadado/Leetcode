class Solution {
public:
    bool checkPossibility(vector<int>& nums) {
        int cnt = 0;
        int cur_min = INT_MIN;
        int n = nums.size();
        for(int i=0; i<n-1; i++){
            if(nums[i]<=nums[i+1]){
                cur_min = nums[i];
            }
            else{
                if(nums[i+1] < cur_min){
                    nums[i+1] = nums[i];
                }
                cnt++;
            }
        }
        return cnt<=1;
    }
};
