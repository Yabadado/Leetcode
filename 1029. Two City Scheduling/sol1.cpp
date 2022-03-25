class Solution {
public:
    int twoCitySchedCost(vector<vector<int>>& costs) {
        sort(costs.begin(), costs.end(), [&](const vector<int> &v1, const vector<int> &v2){ return abs(v1[0]-v1[1]) > abs(v2[0]-v2[1]); });
        int ret = 0;
        int r = 0, l = 0, cur_cost = 0, n = costs.size();
        
        for(auto &c:costs){
            if(l < n/2 && r < n/2){
                cur_cost = min(c[0], c[1]);
                ret += cur_cost;
                cur_cost == c[0] ? l++ : r++;
            }
            else if(l < n/2){
                ret += c[0];
                l++;
            }
            else if(r < n/2){
                ret += c[1];
                r++;
            }
        }
        return ret;
    }
};
