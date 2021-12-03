class Solution {
public:
    int lengthOfLongestSubstringTwoDistinct(string s) {
          
        unordered_map<char, int> mp;
        int idx = 0;
        int preidx = 0;
        int ans = 0;
        while(idx < s.size()){
            
            if(mp.find(s[idx])!=mp.end()){
                mp[s[idx]] = idx;
            }
            else if(mp.size()==2){
                auto first = mp.begin();
                auto sec = first++;
                if(first->second > sec->second){
                    preidx = sec->second+1;
                    mp.erase(sec);
                }else{
                    preidx = first->second+1;
                    mp.erase(first);
                }
            }
            mp[s[idx]] = idx;
            ans = max(ans, idx-preidx+1);
            idx++;
        }
        return ans;
    }
};


/*
    unordered_map<char, int> //recording last index;
    one pass 
    if c in mp
        update c index
    if c != f or s(mp size == 2)
        update ans and pop pre index
    

*/