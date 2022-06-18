class Solution {
public:
    int furthestBuilding(vector<int>& heights, int bricks, int ladders) {
        priority_queue<int> pq;
        for(int i=1; i<heights.size(); i++){
            int cost = heights[i] - heights[i-1];
            if(cost>0){
                if(bricks >= cost){
                    bricks-=cost;
                    pq.push(cost);
                }
                else if(ladders>0){
                    if(!pq.empty() && cost <= pq.top()){
                        bricks += pq.top();
                        pq.pop();
                        pq.push(cost);
                        bricks -= cost;
                    }
                    ladders--;
                }
                else{
                    return i-1;
                }
            }
        }
        return heights.size()-1;
    }
};
