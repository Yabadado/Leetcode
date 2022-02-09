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

/* optimize */
class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        
        for(int i=0; i<nums.size(); i++){
            mp[nums[i]]++;
        }
        sort(nums.begin(), nums.end());
        
        int i = 0, j = 0;
        int ans =0;
        
        for(; i<nums.size();i++){
            if(i!=0 && nums[i]==nums[i-1])
                continue;
            
            int target = nums[i] + k;
            
            if(mp.find(target) != mp.end()){
                
                if(target == nums[i] && mp[target]==1 )
                    continue;
                
                ans++;
            }
        }
        
        return ans;
    }
};
