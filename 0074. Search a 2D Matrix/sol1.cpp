class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size(), n = matrix[0].size();
        
        for(int i=0; i<m; i++){
            if(matrix[i][0] <= target && matrix[i].back() >= target){
                if(target == *lower_bound(matrix[i].begin(), matrix[i].end(), target)){
                    return true;
                }
            }
        }
        return false;
    }
};
