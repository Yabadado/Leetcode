class Solution {
public:
    int lengthOfLongestSubstring(string s) {

        int ans = 0;
        set<char> contain;
            
        int i = 0, j = 0;
        while(j < s.size()){
            if(contain.find(s[j])!=contain.end()){
                contain.erase(contain.find(s[i]));
                i++;
            }
            else{
                contain.insert(s[j]);
                ans = max(ans, j-i+1);
                j++;
            }
        }
        return ans;        
    }
};
