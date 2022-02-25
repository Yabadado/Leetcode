class Solution {
public:
    int compareVersion(string ver1, string ver2) {
        int i =0, j=0;
        int num1=0, num2 =0;
        int m = ver1.size(), n = ver2.size();
        while(i<m || j<n){
            num1 = 0;
            num2 = 0;
            while(i<m && ver1[i]!='.'){
                num1*=10;
                num1 += ver1[i]-'0';
                i++;
            }
            while(j<n && ver2[j]!='.'){
                num2*=10;
                num2 += ver2[j]-'0';
                j++;
            }
            
            if(num1 > num2){
                return 1;
            }else if(num1 < num2){
                return -1;
            }
            
            i++;
            j++;
        }
        
        return 0;
    }
};
