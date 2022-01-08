//博翔
class Solution {
public:
    
    void backtrack(int n, string s, string w, vector<string>&ret, bool isNum){
        
        if(n==0){
            ret.push_back(s);
            return;
        }
        
        
        string tmp=s;
        if(!isNum){
            for(int i=n; i>0 && n-i>=0; i--){
                backtrack(n-i, s+to_string(i), w, ret, 1);
            }
        }
        s = tmp + w[w.size()-n];
        backtrack(n-1, s, w, ret, 0);
        s = tmp;
        
        
    }
    
    vector<string> generateAbbreviations(string word) {
        vector<string> ret;
        backtrack(word.size(), "", word, ret, 0);
        return ret;
    }
};
