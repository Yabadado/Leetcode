class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        
        priority_queue<int> pq(stones.begin(), stones.end());
        
        int n = stones.size()-1;
        while(pq.size()>1){
            int p1 = pq.top(); pq.pop();
            int p2 = pq.top(); pq.pop();
            pq.push(p1-p2);
        }
        return pq.size()==1 ? pq.top() : 0;
    }
};
