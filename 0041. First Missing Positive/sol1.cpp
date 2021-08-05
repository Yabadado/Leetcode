class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
       if(nums.size()==0)return 1;
      
       int arr[nums.size()+1]={0},num;
       for(auto x:nums){
         if(x>0 && x<=nums.size())arr[x-1]=x;
       }
      for(int index=0;index<=nums.size();index++){
        if(arr[index]!=index+1)return index+1;
      }
      return nums.size();
    }
};