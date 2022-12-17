class Solution {
public:
    
    int numberOfPaths(vector<vector<int>>& grid, int k) {
        //mod 1e9+7
        int MOD = 1e9+7;
        int m = grid.size(), n = grid[0].size();
        
        vector<vector<vector<int>>> count(m, vector<vector<int>>(n, vector<int>(k,0)));
        
        count[0][0][grid[0][0]%k]=1; 
        
        for(int j=1; j<n; j++)
            for(int _k=0; _k < k; _k++)
                count[0][j][(grid[0][j]+_k)%k] = count[0][j-1][_k];
        for(int i=1; i<m; i++)
            for(int _k=0; _k < k; _k++)
                count[i][0][(grid[i][0]+_k)%k] = count[i-1][0][_k];

        for(int i=1; i<m; i++)
        {
            for(int j=1; j<n; j++)
            {
                vector<int> update(k);

                for(int _k=0; _k < k; _k++)
                    update[(grid[i][j]+_k)%k] = (count[i][j-1][_k] + count[i-1][j][_k])%MOD;
                count[i][j] = update;
            }
        }
        return (count[m-1][n-1][0])%MOD;
    }
};
