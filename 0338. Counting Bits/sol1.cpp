class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> ret(n+1,0);
        
        int tmp = 0, cnt = 0;
        
        for(int i=0; i<=n; i++){
            tmp = i, cnt=0;
            while(tmp){
                cnt += (tmp&1);
                tmp>>=1;
            }
            ret[i] = cnt;
        }
        return ret;
    }
};
