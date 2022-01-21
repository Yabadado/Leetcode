class Solution {
public:
    
    void helper(int idx, vector<int> cur, int target, int sum, vector<int> &candidates, vector<vector<int>> &ret){
        
        if(sum==target)
            ret.push_back(cur);
        
        if(idx>=candidates.size())
            return;
        
        for(int i=idx; i<candidates.size(); i++){
            if(sum+candidates[idx]> target)
                return;
            cur.push_back(candidates[i]);
            helper(i+1, cur, target, sum+candidates[i], candidates, ret);
            cur.pop_back();
            while(i+1<candidates.size() && candidates[i]==candidates[i+1])i++;
        }
    }
    
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> ret;
        helper(0, {}, target, 0, candidates, ret);
        return ret;
    }
};
