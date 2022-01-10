class Solution {
public:
    bool checkValid(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int sum = n*(n+1)/2;
        
        for(int i=0; i<n; i++){
            unordered_set<int> row;
            for(int j=0; j<matrix[i].size(); j++){
                row.insert(matrix[i][j]);
                if(i!=0){
                    matrix[0][j] += matrix[i][j];
                }
            }
            if(row.size()!=n)
                return false;
        }
        for(int i=0; i<matrix[0].size(); i++){
            if(matrix[0][i]!=sum)
                return false;
        }
        return true;
    }
};
