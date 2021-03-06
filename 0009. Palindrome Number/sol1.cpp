class Solution {
public:
    bool isPalindrome(int x) {
        if(x < 0) return false;
        
        long int ans = 0;
        long int tmp = x;
        
        while(tmp>0){
            ans*=10;
            ans+=tmp%10;
            tmp/=10;
        }
        
        return ans==x;
    }
};