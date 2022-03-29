class Solution {
public:
    int firstBadVersion(int n) {
        int l = 1, r = n;
        int mid;
        int ret = 1;
        while(l <= r){
            mid = l + (r-l) /2;
            if(isBadVersion(mid)){
                ret = mid;
                r = mid-1;
            }
            else{
                l = mid+1;
            }
        }
        return ret;
    }
};
