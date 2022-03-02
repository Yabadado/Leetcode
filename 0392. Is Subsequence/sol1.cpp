class Solution {
public:
    bool isSubsequence(string s, string t) {
        int i = 0, j = 0;
        
        int m = s.size(), n = t.size();
        
        if(m > n)
            return false;
        
        while(j <= n){
            if(s[i]==t[j]){
                i++;
                j++;
            }
            else
                j++;
            if(i>=m){
                return true;
            }
        }
        return false;
    }
};
