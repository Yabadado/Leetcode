class Solution { public: int longestOnes(vector<int>& nums, int k) { 
	int cur_zero = 0; 
	int i=0, j=0; 
	int ans = 0; 
	queue<int> index;
        
        while(j<nums.size()){
            
            if(nums[j]==0){ 
		cur_zero++; index.push(j);
            }
            ans = max(ans, j-i); 
	    j++; 
            if(cur_zero>k){ 
		i = index.front()+1; 
		index.pop(); 
		cur_zero--;
            }
        }
        ans = max(j-i, ans);
        
        return ans;
    }
};
