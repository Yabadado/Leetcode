class Solution {
public:
    char findTheDifference(string s, string t) {
        int r = 0;
        
        for(int i=0; i<s.size(); i++){
            r ^= s[i];
        }
        
        for(int i=0; i<t.size(); i++){
            r ^= t[i];
        }
        return r;
    }
};
