class Solution {
public:
    int ret = 0;
    void helper(vector<int>& heights, int bricks, int ladders, int idx){
        if(idx==heights.size()){
            ret = idx-1;
            return;
        }
        if(heights[idx-1] < heights[idx]){
            if(bricks >= heights[idx]-heights[idx-1]){
                bricks -= (heights[idx] - heights[idx-1]);
                helper(heights, bricks, ladders, idx+1);
                bricks += (heights[idx] - heights[idx-1]);
            }
            if(ladders>0){
                helper(heights, bricks, ladders-1, idx+1);
            }
        }
        else{
            helper(heights, bricks, ladders, idx+1);
        }
        ret = max(ret, idx-1);
    }
    int furthestBuilding(vector<int>& heights, int bricks, int ladders) {
        helper(heights, bricks, ladders, 1);
        return ret;
    }
};

