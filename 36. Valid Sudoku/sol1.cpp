class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {

        //row
        for(int i=0;i<9;i++){
            unordered_map<char,int> mp;
            for(int j=0;j<9;j++){
                if(board[i][j]!='.')
                    mp[board[i][j]]++;
                if(mp[board[i][j]]>1)
                    return false;
            }
            mp.clear();
        }
        
        //col
        for(int i=0;i<9;i++){
            unordered_map<char,int> mp;
            for(int j=0;j<9;j++){
                if(board[j][i]!='.')
                    mp[board[j][i]]++;
                if(mp[board[j][i]]>1)
                    return false;
            }
            mp.clear();
        }
        
        //block
        int loc[3]={0,3,6};
        for(int k=0;k<3;k++){
            for(int l=0;l<3;l++){
                unordered_map<char,int> mp;
                for(int i=0;i<3;i++){       
                    for(int j=0;j<3;j++){
                        if(board[i+loc[k]][j+loc[l]]!='.')
                            mp[board[i+loc[k]][j+loc[l]]]++;
                        if(mp[board[i+loc[k]][j+loc[l]]]>1)
                            return false;
                    }    
                }
                mp.clear();              
            }
        }
        return 1;
    }
};