class Solution {
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        vector<pair<int, int>> score;
        
        for(int i=0; i<mat.size(); i++){
            int s = 0;
            for(int j=0; j<mat[0].size(); j++){
                s += mat[i][j]==1;
            }
            score.push_back({s, i});
        }
        sort(score.begin(), score.end());
        vector<int> ret;
        for(int i=0; i<k; i++){
            ret.push_back(score[i].second);
        }
        return ret.size()==0 ? ret = {0} : ret;
    }
};
