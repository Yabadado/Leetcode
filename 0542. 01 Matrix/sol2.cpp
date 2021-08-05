/*
透過queue，先找出0，再依序pop找周圍的1，此時1的distance為1，再將這些1 push進queue中，找出其他的1->以此類推
*/

class Solution {
public:
    
    struct node{
        node(int i,int j,int l):x(i),y(j),level(l){}
        int x;
        int y;
        int level;
    };
    
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        set<pair<int,int>> mask;
        queue<node>a;
        vector<pair<int,int>> dir= {make_pair(1,0),make_pair(-1,0),make_pair(0,1),make_pair(0,-1)};
        int m = mat.size(), n=mat[0].size();
        vector<vector<int>> ans(m, vector<int>(n,0));
        
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(mat[i][j]==0){
                    node zero(i,j,0);
                    a.push(zero);
                    mask.insert(make_pair(i,j));
                }
            }
        }
        while(a.size()!=0){
            node cur = a.front(); a.pop();
            ans[cur.x][cur.y]=cur.level;
            for(auto &d: dir){
                int x=cur.x+d.first, y=cur.y+d.second, level = cur.level;
                if(x<0 || x==m || y<0 || y==n || mask.count(make_pair(x,y))!=0)
                    continue;
                node next(x,y,level+1);
                a.push(next);
                mask.insert(make_pair(x,y));
            }
        }
        
        return ans;
    }
   
};