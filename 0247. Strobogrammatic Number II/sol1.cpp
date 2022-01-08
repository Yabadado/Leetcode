//博翔
class Solution {
public:
    
    unordered_map<char,char> mapping = {
            {'0', '0'}, {'1', '1'}, {'6', '9'},
            {'8', '8'}, {'9', '6'}
    };
    
    string valid = "01689";
    
    void helper(string cur, vector<string>&ans, int n){
        
        if(cur.size()==(n+1)/2){
            int isOdd = n%2;
            if(isOdd && (cur.back()!=mapping[cur.back()]) ){
               return;
            }
            int len = cur.size()-1-isOdd;
            for(int i=len; i>=0; i--){
                cur+=mapping[cur[i]];
            }
            ans.push_back(cur);
            return;
        }
        
        for(int i=0 ;i<valid.size(); i++){
            string origin = cur;
            cur+=valid[i];
            helper(cur,ans,n);
            cur = origin;
        }
    }
    
    vector<string> findStrobogrammatic(int n) {
        if(n==1) return {"0","1","8"};
        vector<string> ans;
        for(int i=1; i<valid.size(); i++){
            helper(valid.substr(i,1), ans, n);
        }
        return ans;
    }
};