class Solution {
public:
    int minDeletions(string s) {
        vector<int> counter(26, 0);
        for(auto &c:s){
            counter[c-'a']++;
        }
        sort(counter.rbegin(), counter.rend());
        int ret = 0, cur = INT_MAX;
        for(auto c:counter){
            if(c==0) break;
            cur = min(max(cur,0), c);
            ret += c-cur;
            cur--;
        }
        
        return ret;
    }
};

