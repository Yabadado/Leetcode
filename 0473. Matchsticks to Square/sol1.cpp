class Solution {
public:
    bool helper(vector<int> &sticks, int idx, int &mask, int cur, int target, int edge){
        if(edge == 1)
            return true;

        if(cur == target)
            return helper(sticks, 0, mask, 0, target, edge-1);
        
        bool ret = false;
        for(int i=idx; i<sticks.size(); i++){
            if( (mask & 1<<i) || cur+sticks[i] > target) 
                continue;
            
            mask |= 1<<i;
            if(helper(sticks, i+1, mask, cur+sticks[i], target, edge))
                return true;
            mask ^= 1<<i;
        }
        return false;
    }
    bool makesquare(vector<int>& matchsticks) {
        int sum = accumulate(matchsticks.begin(), matchsticks.end(), 0);
        sort(matchsticks.begin(), matchsticks.end());
        int mask =0;
        return sum%4==0 && matchsticks.size()>=4 ? helper(matchsticks, 0, mask, 0, sum/4, 4) : false;
    }
};
