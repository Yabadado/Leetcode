class Solution {
public:
    string convert(string s, int numRows) {
        vector<vector<char>> tmp(numRows, vector<char>());
        string ans;
        
        int ptr = 0;
        int toggle = numRows==1 ? 0 : 1;
        for(int i=0; i<s.size(); i++){
            tmp[ptr].push_back(s[i]);
            ptr+=toggle;
            if(ptr==0||ptr==numRows-1){
                toggle = toggle*-1;
            }
        }
        for(int i=0; i<tmp.size(); i++){
            for(int j=0; j<tmp[i].size(); j++){
                ans+=tmp[i][j];
            }
        }
        return ans;
    }
};