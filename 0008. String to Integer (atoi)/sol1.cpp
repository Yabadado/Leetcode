class Solution {
public:
    int myAtoi(string s) {
        int ret = 0;
        bool sign = false;
        int i=0;
        int n = s.size();
        while(i<n && s[i]==' '){
            i++;
        }
        
        if(s[i]=='+'){
            sign = false;
            i++;
        }
        else if(s[i]=='-'){
            sign = true;
            i++;
        }
        
        while(i<n && isdigit(s[i])){
            int digit = s[i] -'0';
            if( (ret>INT_MAX/10) || (ret == INT_MAX/10 && digit > INT_MAX%10) ){
               return sign ? INT_MIN : INT_MAX;
            }
            ret = ret*10 + digit;
            i++;
        }
        return sign ? -ret : ret;
    }
};
