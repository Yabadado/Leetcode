class Solution {
public:
    int numberOfSteps(int num) {
        int times = 0;
        while(num>0){
            num%2==0 ? num/=2 : num-=1;
            times++;
        }
        return times;
    }
};
