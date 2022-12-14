class Solution {
public:
    int rob(vector<int>& nums) {
        int rob = INT_MIN, cooldown = 0;
        for(int &n:nums)
        {
            int tmp = cooldown;
            cooldown = max(cooldown, rob);
            rob = tmp+n;
        }
        return max(rob, cooldown);
    }
};

