//floyd warshall
class Solution {
public:
    
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries)     {
        unordered_map<string, unordered_map<string, double>> dis;
        for(int i=0; i<equations.size(); i++){
            dis[equations[i][0]][equations[i][1]] = values[i];
            dis[equations[i][1]][equations[i][0]] = 1/values[i];
            dis[equations[i][0]][equations[i][0]] = 1;
            dis[equations[i][1]][equations[i][1]] = 1;
        }
        
        for(auto relay=dis.begin(); relay!=dis.end(); relay++){
            for(auto from=dis.begin(); from!=dis.end(); from++){
                for(auto to=dis.begin(); to!=dis.end(); to++){
                    from->second[to->first] = max(
                        from->second[to->first], 
                        from->second[relay->first] * relay->second[to->first]
                    );
                }
            }
        }
        
        vector<double> ret(queries.size(), 0);
        for(int i=0; i<queries.size(); i++){
            ret[i] = dis[queries[i][0]][queries[i][1]] == 0 ? -1 : dis[queries[i][0]][queries[i][1]];
        }
        
        return ret;
    }
};//floyd warshall
class Solution {
public:
    
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries)     {
        unordered_map<string, unordered_map<string, double>> dis;
        for(int i=0; i<equations.size(); i++){
            dis[equations[i][0]][equations[i][1]] = values[i];
            dis[equations[i][1]][equations[i][0]] = 1/values[i];
            dis[equations[i][0]][equations[i][0]] = 1;
            dis[equations[i][1]][equations[i][1]] = 1;
        }
        
        for(auto relay=dis.begin(); relay!=dis.end(); relay++){
            for(auto from=dis.begin(); from!=dis.end(); from++){
                for(auto to=dis.begin(); to!=dis.end(); to++){
                    from->second[to->first] = max(
                        from->second[to->first], 
                        from->second[relay->first] * relay->second[to->first]
                    );
                }
            }
        }
        
        vector<double> ret(queries.size(), 0);
        for(int i=0; i<queries.size(); i++){
            ret[i] = dis[queries[i][0]][queries[i][1]] == 0 ? -1 : dis[queries[i][0]][queries[i][1]];
        }
        
        return ret;
    }
};
