//博翔
class Solution {
public:
    int lengthOfLongestSubstringKDistinct(string s, int k) {
        int n = s.size();
        
        if(k==0)
            return 0;
        
        unordered_map<char,int> index;
        
        int i = 0, j = 0;
        int ans = 0;
        
        while(j < n){
            
            index[s[j]] = j;
            
            if(index.size()==k+1){
                int smallest = INT_MAX;
                for(auto pair : index){
                    smallest = min(smallest, pair.second);
                }    
                index.erase(s[smallest]);
                i = smallest+1;
            }
            ans = max(ans, j-i+1);
            j++;
        }
        
        return ans;
    }
};
