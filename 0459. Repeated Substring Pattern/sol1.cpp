class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        int len = s.size()/2;
        
        for(int i=len; i>=1; i--){
            
            if(s.size()%i!=0)
                continue;
            string tmp = s.substr(0, i);
            bool match = true;
            for(int j=i; j<s.size(); j+=i){
                if(tmp != s.substr(j, i)){
                    match = false;
                    break;
                }
            }
            if(match)
                return true;
            
        }
        return false;
    }
};
