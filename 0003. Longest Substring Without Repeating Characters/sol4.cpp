class Solution {
public:

    int lengthOfLongestSubstring(string s) {
        int l=0, r = 0;
        unordered_map<char, int> lastIdx;
        int ret = 0;
        for(r=0; r<s.size(); r++){
            if(lastIdx.find(s[r])!=lastIdx.end() && lastIdx[s[r]] > l){
                l = lastIdx[s[r]];
            }
            lastIdx[s[r]] = r+1;
            ret = max(ret, r-l+1);
        }
        return ret;
    }
};
