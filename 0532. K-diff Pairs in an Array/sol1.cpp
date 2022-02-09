class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        unordered_map<int, vector<int> > mp;
        
        for(int i=0; i<nums.size(); i++){
            mp[nums[i]].push_back(i);
        }
        sort(nums.begin(), nums.end());
        
        int i = 0, j = 0;
        int ans =0;
        
        for(; i<nums.size();i++){
            if(i!=0 && nums[i]==nums[i-1])
                continue;
            
            int target = nums[i] + k;
            
            if(mp.find(target) != mp.end()){
                
                if(target == nums[i] && mp[target].size()==1 )
                    continue;
                
                ans++;
            }
        }
        
        return ans;
    }
};


/*
1. hash table -> int, vector(index)
2. sort + two pointer
*/
