class Solution {
public:
    string frequencySort(string s) {
        int n = s.size();
        vector<string> bucket(n+1, "");
        unordered_map<char, int> freq;
        
        int high = INT_MIN, low = INT_MAX;
        for(char &c: s){
            freq[c]++;
        }
        for(auto f: freq){
            bucket[f.second] += f.first;
            high = max(high, f.second);
            low = min(low, f.second);
        }
        
        string ret ="";
        for(int i=high; i>=low; i--){
            for(int j=0; j< bucket[i].size(); j++){
                string tmp(i, bucket[i][j]);
                ret += tmp;
            }
        }

        return ret;
    }
};
