class Solution {
public:
    
    void helper(int k, int n, int idx, vector<vector<int>> &ans, vector<int> tmp){
        
        if(n==0 && tmp.size()==k){
            ans.emplace_back(tmp);
            return;
        }
        
        for(int i=idx; i<=9; i++){
            if(n-i<0)
                break;
            tmp.push_back(i);
            helper(k, n-i, i+1, ans, tmp);
            tmp.pop_back();
        }
        
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        if((1+k)*k > 2*n || (9+k)*k < 2*n)
            return {};
        vector<vector<int>> ans;
        helper(k, n, 1, ans, {});
        return ans;
    }
};
