class Solution {
public:
    int subtractProductAndSum(int n) {
        int mul = 1;
        int add = 0;
        
        while(n!=0){
            int _n = n%10;
            mul *= _n;
            add += _n;
            n /= 10;
        }

        return mul - add;
    }
};
