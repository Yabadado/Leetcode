class Solution {
public:

    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> wordset;
        for(auto s:wordDict){
            wordset.insert(s);
        }
        vector<bool>dp(s.size()+1,0);
        dp[0] = true;
        
        for(int i=1; i<=s.size(); i++){
            for(int j=i; j>=0; j--){
                if(dp[j] && wordset.find(s.substr(j, i-j))!=wordset.end()){
                    dp[i] = true;
                    break;
                }
            }
        }
        return dp[s.size()];
    }
};
