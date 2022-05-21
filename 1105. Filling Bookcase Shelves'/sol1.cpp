class Solution {
public:
    
    unordered_map<int, int> memo;
    
    int helper(vector<vector<int>>&book, int Limit, int idx){
        if(idx==book.size()){
            return 0;
        }
        
        if(memo.find(idx)!=memo.end()){
            return memo[idx];
        }
        
        int width = 0;
        int LayerHeight = 0;
        int ans = INT_MAX;
        
        for(int i=idx; i<book.size(); i++){
            width += book[i][0];
            if(width > Limit){
                break;
            }
            LayerHeight = max(LayerHeight, book[i][1]);
            ans = min(ans, LayerHeight+helper(book, Limit, i+1));
        }
        memo[idx] = ans;
        return ans;
    }
    
    int minHeightShelves(vector<vector<int>>& books, int shelfWidth) {
        return helper(books, shelfWidth, 0);
    }
};
