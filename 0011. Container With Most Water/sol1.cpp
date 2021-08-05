class Solution {
public:
    int maxArea(vector<int>& height) {
        int left = 0;
        int right = height.size()-1;
        int ans = 0;
        
        while(left<right){
            if(height[left] > height[right]){
                ans = max(ans, height[right]*(right-left));
                right--;
            }
            else{
                ans = max(ans, height[left]*(right-left));
                left++;
            }
        }
        return ans;
    }
};