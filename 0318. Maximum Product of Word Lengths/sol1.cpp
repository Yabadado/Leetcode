class Solution {
public:
    
    int getMask(string &s){
        int ret = 0;
        for(auto &c:s){
            ret |= (1<<(c-'a'));
        }
        return ret;
    }

    int maxProduct(vector<string>& words) {
        int ret = 0;
        
        unordered_map<string, int> mp;
        
        for(auto w:words){
            mp[w] = getMask(w);
        }
        
        
        for(int i=0; i<words.size(); i++){
            for(int j=i+1; j<words.size(); j++){
                if( !(mp[words[i]]&mp[words[j]]) ){
                    ret = max(ret, (int)words[i].size()*(int)words[j].size());
                }
            }
        }
        
        return ret;
    }
};
