class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        unordered_set<int> s;
        queue<int> q, q1;
        
        q.push(amount);
        //s.insert(amount);
        int layer = 0;
        
        while(!q.empty()){
            while(!q.empty()){
                int tmp = q.front(); q.pop();
                
                if(tmp<0)
                    continue;
                if(tmp==0)
                    return layer;
                
                for(auto &c:coins){
                    if(s.find(tmp-c)==s.end()){
                        s.insert(tmp-c);
                        q1.push(tmp-c);
                    }
                }
            }
            swap(q, q1);
            layer++;
        }
        
        return -1;
    }
};
