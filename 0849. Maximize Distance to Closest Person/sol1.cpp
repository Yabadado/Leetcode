class Solution {
public:
    int maxDistToClosest(vector<int>& seats) {
        int maxdis = 0;
        int last = -1;
        for(int i=0; i<seats.size(); i++){
            if(seats[i]==1){
                if(last == -1)
                    maxdis = i;
                else
                    maxdis = max(maxdis, (i-last)/2);
                last = i;
            }
        }
        if(!seats.back())
            maxdis = max(maxdis, int(seats.size()-last-1) );
        
        return maxdis;
    }
};
