class Solution {
public:
    
    int change(vector<vector<int>>& board, int x, int y){
        int alive=0, dead = 0;
        for(int i=(x-1>=0 ? x-1 : 0); i<=x+1 && i<board.size(); i++){
            for(int j=(y-1>=0 ? y-1 : 0); j<=y+1 && j<board[0].size(); j++){
                if(i!=x || j!=y){
                    board[i][j]&1 ? alive++ : dead++;
                }
            }
        }
        //cout<<x<<" "<<y<<" "<<alive<<endl;
        if(board[x][y]==1){
            if(alive<2 || alive>3)
                return 1;
            return 3;
        }
        else{
            if(alive ==3){
                return 2;
            }
        }
        return 0;
    }
    
    void gameOfLife(vector<vector<int>>& board) {
        /*
            改變是同時的 所以用2 pass
            0->0 => 0
            0->1 => 2
            1->0 => 1 
            1->1 => 3
            
            1 -> 少於2個1 -> 1
              -> 2 ~3 個 1 -> 3
              -> > 3個1  -> 1
            0 -> 3個1 -> 2
            其他 => 0
        */
        
        for(int i=0; i<board.size(); i++){
            for(int j=0; j<board[i].size(); j++){
               
                board[i][j] = change(board, i, j);
            }
        }
        for(int i=0; i<board.size(); i++){
            for(int j=0; j<board[i].size(); j++){
                board[i][j]>>=1;
            }
        }
        
    }
};
