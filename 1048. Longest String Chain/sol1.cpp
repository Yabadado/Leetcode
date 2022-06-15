class Solution {
public:
    int longestStrChain(vector<string>& words) {
        sort(words.begin(), words.end(), [&](const string &s1, const string &s2){return s1.size() < s2.size();});

        int ret = 0;
        unordered_map<string, int> mp;
        
        for(auto word: words){
            string tmp = word;
            int cur = 0;
            for(int i=0; i<word.size(); i++){
                word.erase(i,1);
                cur = max(cur, mp[word]);
                word = tmp;
            }
            mp[tmp] = cur+1;
            ret = max(ret, mp[tmp]);
        }
        
        return ret;
    }
};

