class Solution {
public:
    bool hasAllCodes(string s, int k) {
        int len = 1<<k;
        
        vector<bool> contains(len, false);
        
        int mask = len-1;
        int val = 0;
        for(int i=0; i<s.size(); i++){
            val = ((val<<1)&mask) | (int)(s[i]-'0');
            
            if(i>=k-1 && !contains[val]){
                contains[val] = true;
                len--;
                if(len==0) return true;
            }
        }
        return false;
    }
};
