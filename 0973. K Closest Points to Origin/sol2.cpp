class Solution {
public:
    
    int dis(vector<int>& p){
        return p[0]*p[0] + p[1]*p[1];
    }
    
    
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<pair<int, int>> p; //pair-> (dis, index)
        
        for(int i=0; i<points.size(); i++){
            p.push({dis(points[i]), i});
            if(p.size() > k){
                p.pop();
            }
        }
        vector<vector<int>> ret;
        while(!p.empty()){
            int idx = p.top().second;
            ret.push_back(points[idx]);
            p.pop();
        }
        return ret;
    }
};
