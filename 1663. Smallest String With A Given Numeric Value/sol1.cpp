class Solution {
public:
    string getSmallestString(int n, int k) {
        string ret = "";
        vector<char> ch(26);
        for(int i=0; i<26; i++)
            ch[i] = char(i+97);
        
        for(int i=0; i<n; i++){
            ret+="a";
        }
        
        while(n>0){
            if(k-n > 25){
                ret[n-1] = 'z';
                k-=26;
                n--;
            }
            else{
                ret[n-1] = ch[k-n];
                k-=(k-n+1);
                n--;
            }
            if(k==n){
               break;
            }
        }
    
        return ret;
    }
};
