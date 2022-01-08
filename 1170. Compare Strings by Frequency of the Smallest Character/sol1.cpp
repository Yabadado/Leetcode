class Solution {
public:
    
    int freq(string &s){
        char cur_min = 'z';
        int cnt = 0;
        for(char &c:s){
            if(c<cur_min){
                cur_min = c;
                cnt = 0;
            }
            if(c==cur_min)
                cnt++;
        }
        return cnt;
    }
    
    
    vector<int> numSmallerByFrequency(vector<string>& queries, vector<string>& words) {
        
        vector<int> w_freq;
        
        //init word frequency
        for(string &s:words){
            int wfreq = freq(s);
            w_freq.push_back(wfreq);
        }
        
        sort(w_freq.begin(), w_freq.end());
        
        vector<int> ans;
    
        for(string &s:queries){
            int query_freq = freq(s);
            int rank = (int)(w_freq.end() - upper_bound(w_freq.begin(), w_freq.end(), query_freq));
            ans.push_back(rank);
        }
        
        return ans;
    }
};