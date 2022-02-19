class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        int n = words.size();
        vector<vector<string>> bucket(n, vector<string>());
        unordered_map<string, int> cnt;
        for(auto &s : words){
            cnt[s]++;
        }
        int high = INT_MIN, low = INT_MAX;
        for(auto f: cnt){
            bucket[f.second].push_back(f.first);
            high = max(high, f.second);
            low = min(low, f.second);
        }
        
        vector<string> ret;
        
        for(int i=high; i>=low && k; i--){
            sort(bucket[i].begin(), bucket[i].end());
            for(auto &s : bucket[i]){
                ret.push_back(s);
                k--;
                if(k==0){
                    break;
                }
            }
        }
        
        return ret;
    }
};class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        int n = words.size();
        vector<vector<string>> bucket(n, vector<string>());
        unordered_map<string, int> cnt;
        for(auto &s : words){
            cnt[s]++;
        }
        int high = INT_MIN, low = INT_MAX;
        for(auto f: cnt){
            bucket[f.second].push_back(f.first);
            high = max(high, f.second);
            low = min(low, f.second);
        }
        
        vector<string> ret;
        
        for(int i=high; i>=low && k; i--){
            sort(bucket[i].begin(), bucket[i].end());
            for(auto &s : bucket[i]){
                ret.push_back(s);
                k--;
                if(k==0){
                    break;
                }
            }
        }
        
        return ret;
    }
};
