class Solution {
public:
    int partitionString(string s) {
        int mask = 0;
        int ans = 0;
        for(int j=0; j<s.size(); j++){
            if( (mask & (1<<(s[j]-'a')))!=0 ){
                mask = 0;
                ans++;
            }
            mask|= (1<<(s[j]-'a'));
        }
        return ans+1;
    }
};
