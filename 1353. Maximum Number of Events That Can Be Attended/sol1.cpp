class Solution {
public:
    int maxEvents(vector<vector<int>>& events) {
        sort(events.begin(), events.end());
        priority_queue<int, vector<int>, greater<int>> q;
        
        int ans = 0, idx=0, today = 0, n = events.size(); 
        
        while(!q.empty() || idx<n){
            
            if(q.empty()){
                today = events[idx][0];
            }
            
            while(idx < n && events[idx][0] == today){
                q.push(events[idx][1]);
                idx++;
            }
            q.pop();	//attend a evnet
            ans++;
            today++;
            
            while(!q.empty() && q.top() < today){
                q.pop();
            }
            
        }
        return ans;
    }
};
