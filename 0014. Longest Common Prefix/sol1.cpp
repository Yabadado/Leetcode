public:
    string longestCommonPrefix(vector<string>& strs) {
        string ans = "";
        bool flag = true;
        char tmp;
        
        sort(strs.begin(),strs.end());
        
        for(int i=0; i<strs[0].size() && flag; i++){
            tmp = strs[0][i];
            for(int j=1; j<strs.size() && flag; j++){
                if(tmp!=strs[j][i]){
                    flag = false;   
                }                
            }
            if(flag)
                ans+=tmp;
        }
        return ans;
    }
};