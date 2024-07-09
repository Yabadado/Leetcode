class Solution {
public:
    double averageWaitingTime(vector<vector<int>>& customers) {
        long curTime = 0, totalWaitingTime = 0, servedTime = 0;
        
        for(auto &customer: customers){
            curTime = max(curTime, (long)customer[0]);
            servedTime = curTime+customer[1];
            totalWaitingTime += (servedTime-customer[0]);
            curTime = servedTime;
        }
        
        return (double)totalWaitingTime/(double)customers.size();
    }
};