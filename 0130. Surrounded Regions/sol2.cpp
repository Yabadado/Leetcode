//Time: O(m*n)
//Space: O( #'O' )

//BFS: 先把邊緣的'O'加到queue中，再逐一擴張修改連接的區域，概念與DFS相似。

class Solution {
public:
    
    void BFS(vector<vector<char>>& board, queue<pair<int,int>> &q){
        
        while(!q.empty()){
            auto node = q.front(); q.pop();
            int m = node.first, n = node.second;
            
            board[m][n] = '.';
            if(m-1>0 && board[m-1][n]=='O')             
                q.push({m-1,n});
            if(m+1<board.size() && board[m+1][n]=='O')  
                q.push({m+1,n});
            if(n-1>0 && board[m][n-1]=='O') 
                q.push({m,n-1});
            if(n+1<board[0].size() && board[m][n+1]=='O') 
                q.push({m,n+1});
        }
        
    }
    
    void solve(vector<vector<char>>& board){
        
        queue<pair<int,int>> pos;
        
        for(int i=0; i<board.size(); i++){
            if(board[i][0]=='O'){
                pos.push({i,0});
            }
            if(board[i][board[0].size()-1]=='O'){
                pos.push({i,board[0].size()-1});
            }
        }
        for(int j=0; j<board[0].size(); j++){
            if(board[0][j]=='O'){
                pos.push({0,j});
            }
            if(board[board.size()-1][j]=='O'){
                pos.push({board.size()-1,j});
            }
        } 
        
        BFS(board, pos);
            
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