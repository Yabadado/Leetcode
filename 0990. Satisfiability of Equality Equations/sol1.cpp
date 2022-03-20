class Solution {
public:
    
    void draw(int root, unordered_map<int, vector<int>> &graph, int color, vector<int> &colored){
        colored[root] = color;
        for(int i=0; i<graph[root].size(); i++){
            int next_node = graph[root][i];
            if(colored[next_node]==0){
                draw(next_node, graph, color, colored);
            }
        }
    }
    
    bool equationsPossible(vector<string>& equations) {
        
        unordered_map<int, vector<int>> graph;
        
        vector<int> colored = vector<int>(26,0);
        
        for(auto &e: equations){
            if(e[1]=='='){
                int a = e[0] - 'a';
                int b = e[3] - 'a';
                graph[a].push_back(b);
                graph[b].push_back(a);
            }
        }
        
        int color = 1;
        for(int i=0; i<26; i++){
            if(colored[i]==0){
                draw(i, graph, color, colored);
                color++;
            }
        }
        
        // for(int i=0; i<26; i++){
        //     cout<<colored[i]<<" ";
        // }cout<<endl;
        
        for(auto &e:equations){
            if(e[1]=='!'){
                int a = e[0]-'a';
                int b = e[3]-'a';
                if(a==b || (a!=b && colored[a]==colored[b])){
                    return false;
                }
            }
        }
        return true;
    }
};
