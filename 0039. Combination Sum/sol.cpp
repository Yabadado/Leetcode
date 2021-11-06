class Solution {
public:
    
    void dfs(vector<int>& candidates, int target, int index, int sum, vector<vector<int>> &ans, vector<int> cur){
        if(sum > target)
            return;
        if(sum==target){
            ans.push_back(cur);
            return; 
        }
        for(int i = index; i<candidates.size(); i++){
            if(sum+candidates[i] > target)
                break;
            cur.push_back(candidates[i]);
            dfs(candidates, target, i, sum+candidates[i], ans, cur);
            cur.pop_back();
        }
    }
    
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> ans;
        vector<int> cur;
        dfs(candidates, target, 0, 0, ans, cur);
        return ans;
    }
};