class Solution {
public:
    int strStr(string haystack, string needle) {
        
        int m = haystack.size();
        int n = needle.size();
        
        if(needle=="")
            return 0;
        
        int i=0, j=0;
        
        for(int i=0; i<m; i++){
            if(haystack[i]==needle[0]){
                for(j=1; j<n; j++){
                    if(haystack[i+j]!=needle[j]){
                        break;
                    }
                }
                if(j==n){
                    return i;
                }
            }
        }
        return -1;   
    }
};
