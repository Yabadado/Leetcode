/*
    // dp solution
*/

class Solution {
public:
    int minFlipsMonoIncr(string s) {
        int count0 = 0, count1 = 0;
        for(int i = 0; i < s.size(); i++){
            count0 += (s[i]=='1');
            count1 = min(count0, count1+(s[i]=='0'));
        }
        return count1;
    }
};