class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        
        int n = temperatures.size();
        
        stack<pair<int,int>> s; //temp, index
        vector<int> ret(n,0);
        
        //遞減monotonic
        for(int i=temperatures.size()-1; i>=0; i--){
            while(!s.empty() && temperatures[i] >= s.top().first){
                s.pop();
            }
            if(s.empty()){
                ret[i] = 0;
            }
            else{
                ret[i] = s.top().second - i;
            }
            
            s.push({temperatures[i], i});
        }

        return ret;
    }
};
