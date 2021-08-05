class Solution {
public:
    void backtrack(vector<vector<int>> &res,vector<int> &visited,vector<int>& nums,vector<int> &v)
    {
        if(v.size()==nums.size())
        {
            res.push_back(v);
            return;
        }
	  
        for(int i=0 ; i<nums.size();i++)
        {
           if(visited[i]==1) continue;
           else
           {
                v.push_back(nums[i]);
                visited[i]=1;
                backtrack(res,visited,nums,v);
                v.pop_back();
                visited[i]=0;
           }
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> v;
        vector<int> visited(nums.size());
        backtrack(res,visited,nums,v);
        return res;
    }
};