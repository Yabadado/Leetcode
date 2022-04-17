class Solution {
public:
    int numSub(string s) {
        long long int sum = 0;
        int M = 1e9+7;
        int i = 0, j=0;
        while(i<s.size() && j<s.size()){
            if(s[i]=='1'){
                j = i;
                
                while(j<s.size() && s[++j]=='1'){}
                long long int a = (j-i+1), b = (j-i);
                
                sum = sum + ((a*b)/2)%M;
                sum %= M; 
                i = j;
            }
            i++;
        }
        return sum;
    }
};
