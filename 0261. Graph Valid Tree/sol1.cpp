class Solution {
public:
    
    vector<int> parent;
    vector<int> size;
    int rootNum;
    
    int find(int x){
        if(parent[x]!=x){
            int p = find(parent[x]);
            parent[x] = p;
        }
        return parent[x];
    }
    
    
    bool Union(int x, int y){
        int px = find(x);
        int py = find(y);
        
        if(px == py){
            return false;
        }
        
        if(size[px] >= size[py]){
            parent[py] = px;
            size[px]+=size[py];
        }
        else{
            parent[px] = py;
            size[py] += size[px];
        }
        
        return true;
    }
    
    bool validTree(int n, vector<vector<int>>& edges) {
        rootNum = n;
        parent = vector<int>(n, 0);
        size = vector<int>(n,1);
        for(int i=0; i<n; i++){
            parent[i] = i;
        }
        
        for(auto &e:edges){
            if(!Union(e[0], e[1])){
                return false;
            }
            rootNum--;
        }
        return rootNum==1;
    }
};
