class Solution {
public:
    
    int search_index(vector<int> &nums2, int target){
        int l=0, r=nums2.size()-1;
        while(l<=r){
            int mid = l+(r-l)/2;
            if(nums2[mid] >= target){
                l = mid+1;
            }
            else{
                r = mid-1;
            }
        }
        return l;
    }
    
    int maxDistance(vector<int>& nums1, vector<int>& nums2) {
        int ret = 0;
        for(int i=0; i<nums1.size();i++){
            //int j = lower_bound(nums2.begin(), nums2.end(), nums1[i],greater<int>())-nums2.begin();
            int j = search_index(nums2, nums1[i])-1;
            
            if(i<=j && nums1[i]<=nums2[j]){
                ret = max(ret, j-i);
            }
        }
        return ret;
    }
};
