class Solution {
public:
    vector<int> getOrder(vector<vector<int>>& tasks) {
        
        int numTask = tasks.size();
        //加入index再sort就可以保證題目要求第二點
        for(int i=0; i<numTask; i++){
            tasks[i].push_back(i);
        }
        sort(tasks.begin(), tasks.end());
        
        //priority queue存 <process time, index>
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<> >pq;
        //初始task 時間 tasks之index
        pq.push({tasks[0][1], tasks[0][2]});
        int idx = 1, time = tasks[0][0];
        
        vector<int> ret;
        
        //issue task -> 要每次做完一個task就重新check時間
        while(idx<numTask){
            //時間內所有task都要enqueue
            while(idx<numTask && time>=tasks[idx][0]){
                pq.push({tasks[idx][1], tasks[idx][2]});
                idx++;
            }
            //process task
            if(!pq.empty()){
                auto [duration, index] = pq.top(); pq.pop();
                ret.push_back(index);
                time += duration;
            }
            else{
                time = tasks[idx][0];
            }
        }
        
        //因為每次只做一個task tasks可能先被拿完，要再檢查priority queue
        while(!pq.empty()){
            auto [duration, index] = pq.top(); pq.pop();
            ret.push_back(index);
        }
        
        return ret;
    }
};
