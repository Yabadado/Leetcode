class Solution {
public:
    string countAndSay(int n) {
        
        string ret = "1";
        
        for(int i=0; i<n-1; i++){
            string tmp = "";
            char cur = ret[0];
            int cnt=0;
            for(int i=0; i<ret.size(); i++){
                if(cur!=ret[i]){
                    tmp+=to_string(cnt) + cur;
                    cur = ret[i];
                    cnt = 1;
                }
                else{
                    cnt++;
                }
                if(i==ret.size()-1){
                    tmp+=to_string(cnt) + cur;
                }
                
            }
            //cout<<tmp<<endl;
            ret = tmp;
        }
        return ret;
    }
};
