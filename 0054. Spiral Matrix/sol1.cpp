class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> ans;
        int m = matrix.size();
        int n = matrix[0].size();
        
        int dim=0;
        
        // 4 dim limit
        int top  = 0;
        int left = 0; 
        int right = n-1;
        int bottom = m-1;
        
        
        while(left<=right && top<=bottom) {
            if(dim==0){
                for(int i=left; i<=right; i++)
                    ans.push_back(matrix[top][i]);
                dim++;
                top++;
            }
            else if(dim==1){
                for(int i=top; i<=bottom; i++)
                    ans.push_back(matrix[i][right]);
                dim++;
                right--;
            }
            else if(dim==2){
                for(int i=right; i>=left; i--)
                    ans.push_back(matrix[bottom][i]);
                dim++;
                bottom--;
            }
            else if(dim==3){
                for(int i=bottom; i>=top; i--)
                    ans.push_back(matrix[i][left]);
                dim=0;
                left++;
            }
        } 
        return ans;
        
    }
};
