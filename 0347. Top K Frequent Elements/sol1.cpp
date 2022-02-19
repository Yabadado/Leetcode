class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        int n = nums.size();
        vector<vector<int>> bucket(n+1, vector<int>());
        unordered_map<int, int> cnt;

        for(int &n:nums){
            cnt[n]++;;
        }
        for(auto i:cnt){
            //cout<<i.first<<"->"<<i.second<<" times"<<endl;
            bucket[i.second].push_back(i.first);
        }
        
        vector<int> ret;
        for(int i=n; i>=0; i--){
            ret.insert(ret.end(), bucket[i].begin(), bucket[i].end());
            if(ret.size()>=k){
                break;
            }
        }
    
        return vector<int>(ret.begin(), ret.begin()+k);
    }
};
