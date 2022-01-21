class Solution {
public:
    
    double dfs(const string &source,const string &target, unordered_map<string, unordered_map<string, double>>&map, unordered_set<string> &visit){
        if(map[source].find(target)!=map[source].end()){
            return map[source][target];
        }
        
        for(auto i:map[source]){
            if(visit.find(i.first)==visit.end()){
                visit.insert(i.first);
                double ret = dfs(i.first, target, map, visit);
                if(ret){
                    return i.second*ret;
                }
            }
        }
        return 0;
    }
    
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        unordered_map<string, unordered_map<string, double> > child;
        for(int i=0; i<equations.size(); i++){
            auto e = equations[i];
            child[e[0]][e[1]] = values[i];
            if(values[i]!=0)
                child[e[1]][e[0]] = 1/values[i];
        }
        
        vector<double> ans;
        for(auto q: queries){
            unordered_set<string> visit;
            double ret = dfs(q[0], q[1], child, visit);
            if(ret!=0)
                ans.push_back(ret);
            else
                ans.push_back(-1);
        }
        return ans;
    }
};
