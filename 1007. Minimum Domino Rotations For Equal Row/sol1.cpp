class Solution {
public:
    int minDominoRotations(vector<int>& tops, vector<int>& bottoms) {
        int t[6] = {0}, d[6] = {0};
        int same[6] = {0};
        int n = tops.size();
        for(int i=0; i<n; i++){
            t[tops[i]-1]++;
            d[bottoms[i]-1]++;
            if(tops[i]==bottoms[i]){
                same[tops[i]-1]++;
            }
        }
        
        int ret = INT_MAX;
        for(int i=0; i<6; i++){
            if(t[i]+d[i]-same[i]==n)
                return n - max(t[i], d[i]);
            //cout<<i+1<<" -> "<<t[i]<<" "<<d[i]<<" "<<same[i]<<endl;
        }
        return -1;
    }
};
