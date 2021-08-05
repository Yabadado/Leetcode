class Solution {
public:
    int reverse(int x) {
        long long int res=0;
        while(x!=0){
            res *= 10;
            res+=  (x % 10);
            x = x/10;
        }
        if(abs(res)>INT_MAX) return 0;
        return (int)res;
    }
};