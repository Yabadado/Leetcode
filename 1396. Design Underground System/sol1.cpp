class UndergroundSystem {
public:
    UndergroundSystem() {
            
    }
    
    void checkIn(int id, string stationName, int t) {
        record[id] = {stationName, t};
    }
    
    void checkOut(int id, string stationName, int t) {
        string key = record[id].first + "_" + stationName;
        int during = t - record[id].second;
        auto &[times, cnt] = Time[key];
        times += during;
        cnt++;
    }
    
    double getAverageTime(string startStation, string endStation) {
        string key = startStation + "_" + endStation;
        return (double)Time[key].first/Time[key].second;
    }
    
    unordered_map<string, pair<int, int>> Time;
    unordered_map<int, pair<string, int>> record;
    
};

/**
 * Your UndergroundSystem object will be instantiated and called as such:
 * UndergroundSystem* obj = new UndergroundSystem();
 * obj->checkIn(id,stationName,t);
 * obj->checkOut(id,stationName,t);
 * double param_3 = obj->getAverageTime(startStation,endStation);
 */
