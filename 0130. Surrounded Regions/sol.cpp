//Time: O(m*n)
//Space: O(1)

//DFS先修改邊界上的'O'相連區域，再將剩下的'O'修改成'X'(因為這些'O'必是被包圍的)，最後復原未被包圍的'O'。
class Solution {
public:
    
    void helper(vector<vector<char>>& board, int i, int j){
        if(i<0 || i==board.size() || j<0 || j==board[0].size() || board[i][j]!='O')
            return;
        board[i][j]='.';
        helper(board, i-1, j  );
        helper(board, i+1, j  );
        helper(board, i  , j-1);    
        helper(board, i  , j+1);
    }
    
    void solve(vector<vector<char>>& board){
        
        for(int i=0; i<board.size(); i++){
            helper(board, i, 0);
            helper(board, i, board[0].size()-1);
        }
        for(int j=0; j<board[0].size(); j++){
            helper(board, 0, j);
            helper(board, board.size()-1, j);
        } 
        
        for(int i=0; i<board.size(); i++){
            for(int j=0; j<board[0].size(); j++){
                if(board[i][j]=='O')
                    board[i][j]='X';
                if(board[i][j]=='.')
                    board[i][j] = 'O';
            }
        }
    }
};