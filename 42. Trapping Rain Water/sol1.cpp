class Solution {
public:
    int trap(vector<int>& height) {
        int l=0, r=height.size()-1;
        int sum=0;
        int l_lim=0, r_lim=0;
        while(l<r){
            if(height[l]<height[r]){
                if(height[l]<l_lim)
                    sum+=l_lim-height[l];
                else
                    l_lim = height[l];  
                l++;
            }
            
            else{
                if(height[r]<r_lim)
                    sum+=r_lim-height[r];
                else
                    r_lim = height[r];  
                r--;
            }
            
        }
        return sum;
    }
};