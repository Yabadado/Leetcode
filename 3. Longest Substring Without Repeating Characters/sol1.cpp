class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int max=0;
        int temp=0;
        //int list[];
        if(s.length()) max=1;
        for(int i=1; i<s.length();i++)
        {
            for(int j=temp;j<i;j++)
            {
                if(s[i]==s[j])
                {
                    max= max > (i - temp) ? max : (i-temp) ;
                    temp = j + 1;
                    break;
                }                
            }
        }
        max= max > (s.length() - temp) ? max : (s.length()-temp) ;
        return max;        
    }
};