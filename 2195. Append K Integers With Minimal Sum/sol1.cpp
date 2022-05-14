class Solution {
public:
    long long minimalKSum(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        long long ans = 0;
        if(nums[0]>1){
            long long hi = min(k, nums[0]-1);
            long long low = 1;
            ans += (hi+low)*(hi-low+1)/2;
            k -= (hi-low+1);
        }
        
        for(int i=0; i<nums.size()-1; i++){
            if(nums[i]==nums[i+1])
                continue;
            long long low = nums[i]+1;
            long long hi = min(nums[i]+k, nums[i+1]-1);
            
            ans += (low+hi)*(hi-low+1)/2;
            k -= (hi-low+1);
            if(k==0)
                break;
        }
        
        if(k>0){
            long long low = nums.back()+1;
            long long hi =  low+k-1;
            ans+= (hi+low)*(hi-low+1)/2;
        }
        
        return ans;
    }
};
