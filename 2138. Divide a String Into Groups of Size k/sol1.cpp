class Solution {
public:
    vector<string> divideString(string s, int k, char fill) {
        vector<string> ret;
        int cnt = s.size()/k;
        
        int idx=0;
        for(int i=0; i<cnt; i++){
            ret.push_back(s.substr(idx, k));
            idx+=k;
        }
        
        if(cnt*k < s.size()){
            string tmp ="";
            for(int i=0; i<k; i++){
                if(idx<s.size())
                    tmp+=s[idx++];
                else
                    tmp+=fill;
            }
            ret.push_back(tmp);
        }
        
        return ret;
    }
};
