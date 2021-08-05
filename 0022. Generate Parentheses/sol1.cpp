class Solution {
public:
    vector<string> ans;
    
    void solve(int left, int right, string cur){
        if(left==right && left==0){
            ans.push_back(cur);
            return;
        }
        if(left>0)
            solve(left-1, right+1, cur+"(");
        if(right>0)
            solve(left, right-1, cur+")");
        
    }
    
    
    vector<string> generateParenthesis(int n) {        
        solve(n, 0, "");
        return ans;
    }
};