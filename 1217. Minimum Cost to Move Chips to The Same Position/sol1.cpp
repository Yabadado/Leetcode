class Solution {
public:
    int minCostToMoveChips(vector<int>& position) {
        vector<int> cnt(2,0);
        
        for(int &p:position){
            cnt[p%2]++;
        }
        
        return min(cnt[0],cnt[1]);
    }
};

/*
從前面掃過去(紀錄奇數堆跟偶數堆)
取最小那堆
*/