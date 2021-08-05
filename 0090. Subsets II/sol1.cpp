/*
核心概念:backtracking，並把找過的組合加入set中。

*/
class Solution {
    
private:
    vector<vector<int>> ans;
    vector<int> subset;
    set<vector<int>> s; //store curreny subset
    
    void backtrack(vector<int> & nums, int index){
        if(index>nums.size()){
            return;
        }
        if(s.find(subset)==s.end()){
            s.insert(subset);
            ans.push_back(subset);
        }
        
        for(int i=index; i<nums.size(); i++){
            subset.push_back(nums[i]);
            backtrack(nums, i+1);
            subset.pop_back();
        }
        
    }
    
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        backtrack(nums, 0);
        
        return ans;
    }
};