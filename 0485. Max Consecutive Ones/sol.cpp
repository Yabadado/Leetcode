//Time: O(n)
//Space: O(1)
class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int tmp=0, ans=0; 
        
        for(auto &n:nums){
            if(n)
                tmp++;
            else
                tmp=0;
            ans = max(tmp, ans);
        }
        return ans;
    }
};