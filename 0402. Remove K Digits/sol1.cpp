class Solution {
public:
    string removeKdigits(string num, int k) {
        int cnt = 0;
        string ret;
        for(char &c:num){
            while(ret!="" && ret.back() > c && k){
                ret.pop_back();
                k--;
            }
            if(ret!="" || c!='0'){
                ret.push_back(c);
            }
        }
        
        while(ret!="" && k){
            ret.pop_back();
            k--;
        }
        
        return ret=="" ? "0" : ret;
    }
};
