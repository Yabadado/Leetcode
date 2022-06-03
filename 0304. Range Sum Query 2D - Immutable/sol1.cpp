class NumMatrix {
public:
    NumMatrix(vector<vector<int>>& matrix) {
        mat = matrix;
        for(int i=0; i<mat.size(); i++){
            for(int j=1;j<mat[0].size(); j++){
                mat[i][j] += mat[i][j-1];
            }
        }
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        int ret = 0;
        for(int i=row1; i<=row2; i++){
            if(col1==0)
                ret+= mat[i][col2];
            else
                ret += mat[i][col2] - mat[i][col1-1];
        }
        return ret;
    }
    vector<vector<int>> mat;
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */
