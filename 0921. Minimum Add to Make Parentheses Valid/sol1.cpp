class Solution {
public:
    int ans = 0;
    int minAddToMakeValid(string s) {
        int cnt = 0;
        //紀錄非閉區間 -> cnt<0 表示要補'('  cnt = 待補 ')' 數量
        for(int i=0; i<s.size(); i++){
            if(s[i]=='(')
                cnt++;
            else if(s[i]==')')
                cnt--;
            if(cnt<0){
                ans++;
                cnt=0;
            }
                
        }
        return ans + cnt;
    }
};
