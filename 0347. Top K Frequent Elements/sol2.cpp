//time: O(n log n)
//space: O(n)
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        //hash -> value前兩大
        map<int, int> count;
        vector<pair<int,int>> freq;
        int top = 0, sec =0;
        for(int i:nums){
            count[i]++;
        }
        
        for(auto it:count){
            freq.push_back(make_pair(it.second, it.first));
        }
        
        sort(freq.rbegin(), freq.rend());
        
        vector<int> ans;
        for(int i=0; i<k; i++){
            ans.push_back(freq[i].second);
        }
        
        return ans;
        
    }
};//time: O(n log n)
//space: O(n)
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        //hash -> value前兩大
        map<int, int> count;
        vector<pair<int,int>> freq;
        int top = 0, sec =0;
        for(int i:nums){
            count[i]++;
        }
        
        for(auto it:count){
            freq.push_back(make_pair(it.second, it.first));
        }
        
        sort(freq.rbegin(), freq.rend());
        
        vector<int> ans;
        for(int i=0; i<k; i++){
            ans.push_back(freq[i].second);
        }
        
        return ans;
        
    }
};
