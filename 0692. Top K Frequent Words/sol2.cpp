class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        int n = words.size();
        vector<vector<string>> bucket(n, vector<string>());
        unordered_map<string, int> cnt;
        for(auto &s : words){
            cnt[s]++;
        }
        set<int> index;
        for(auto f: cnt){
            bucket[f.second].push_back(f.first);
            index.insert(f.second);
        }
        
        priority_queue<int> pq;
        for(const int &i:index){
            pq.push(i);
        }
        
        vector<string> ret;
        
        while(!pq.empty() && k){
            int i = pq.top(); pq.pop();
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
