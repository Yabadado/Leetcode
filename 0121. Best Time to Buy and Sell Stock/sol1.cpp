class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int hold = INT_MAX, sell = 0; 

        for(int i=0; i<prices.size(); i++){
            hold = min(hold, prices[i]);
            sell = max(prices[i] - hold, sell);
        }
        
        return sell;
    }
};
