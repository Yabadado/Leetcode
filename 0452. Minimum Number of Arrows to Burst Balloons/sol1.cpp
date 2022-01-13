class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        
        sort(points.begin(), points.end(), [](vector<int>& p1, vector<int> &p2){return p1[1] < p2[1];});
        
        int curPos = points[0][1];
        int cnt = 1;
        for(int i=0; i<points.size(); i++){
            if(curPos>=points[i][0]){
                continue;
            }
            cnt++;
            curPos = points[i][1];
        }
        return cnt;
    }
};
