//Time Complexity: O(n) -> n = maxlen(x,y)
//Space Complexity:O(1)
class Solution {
public:
    int hammingDistance(int x, int y) {
        x = x^y;
        int cnt = 0;
        while(x){
            cnt += int(x%2);
            x>>=1;    
        }
        return cnt;
    }
};



