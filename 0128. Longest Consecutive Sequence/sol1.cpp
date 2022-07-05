class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> s;
        for(auto &n:nums){
            s.insert(n);
        }
        int maxLen = 0;
        for(int &n:nums){
            if(s.find(n-1)==s.end()){
                int cur = n;
                int curLen = 1;
                while(s.find(cur+1)!=s.end()){
                    cur++;
                    curLen++;
                }
                maxLen = max(maxLen, curLen);
            }
        }
        return maxLen;
    }
};
