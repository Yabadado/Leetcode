class Solution {
public:
    int minSpeedOnTime(vector<int>& dist, double hour) {
        
        int l = 1, r = 1e7;
        int ans = -1;
        while(l <= r){
            int speed = l + (r-l)/2;
            if(meetDL(dist, hour, speed)){
                ans = speed;
                r = speed - 1;
                
            }
            else{
                l = speed + 1;
            }
        }
        
        return ans;
    }
    
    bool meetDL(vector<int>& dist, double hour, int speed){
        
        double time = 0;
        
        for(int i=0; i<dist.size(); i++){
            time = ceil(time);
            time += (double)dist[i]/(double)speed;
        }
        
        return time <= hour;
    }
};
