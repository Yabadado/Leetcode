class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int candidate = 0;
        int cnt = 0;
        for(int &n: nums){
            
            n == candidate ? cnt++ : cnt--;
            
            if(cnt<=0){
                candidate = n;
                cnt = 1;
            }
        }
        return candidate;
    }
};
