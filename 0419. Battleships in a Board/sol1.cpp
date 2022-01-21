class Solution {
public:
    
    void helper(vector<vector<char>>& board, int x, int y){
        if(x<0 || x==board.size() || y<0 || y==board[0].size() || board[x][y]=='.'){
            return;
        }
        
        board[x][y] = '.';
        
        helper(board, x+1, y);
        helper(board, x-1, y);
        helper(board, x, y+1);
        helper(board, x, y-1);
    }
    
    int countBattleships(vector<vector<char>>& board) {
        
        int ans = 0;
        for(int i=0; i< board.size(); i++){
            for(int j=0; j<board[i].size(); j++){
                if(board[i][j]=='X'){
                    ans++;
                    helper(board,i,j);
                }
            }
        }
        
        return ans;
    }
};
