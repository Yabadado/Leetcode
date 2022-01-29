class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int ans = 0;
        
        unordered_map<char, int> has;
        queue<pair<char, int>> order;
            
        int i = 0, j = 0;
        for(j = 0; j < s.size(); j++){
            if(has.find(s[j])!=has.end()){
                while(!order.empty() && order.front().second <= has[s[j]] ){
                    i = order.front().second + 1;
                    has.erase(order.front().first);
                    order.pop();
                }
            }
            has[s[j]] = j;
            order.push({s[j], j});
            ans = max(ans, j-i+1);
        }
        return ans;        
    }
};
