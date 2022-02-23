class Solution {
public:
    vector<int> findOriginalArray(vector<int>& changed) {
        if(changed.size()%2)
            return {};
        
        map<int, int> fre;    // num, index
        for(int n:changed){
            fre[n]++;
        }
        
        vector<int> ret;
        for(auto n: fre){
            if(n.first==0){
                if(n.second%2){
                    return {};
                }
                for(int i=0;i<n.second/2; i++)
                    ret.push_back(n.first);
                fre.erase(n.first);
            }
            else{
                int target = n.first*2;
                if(fre.find(target)==fre.end() || fre[target]<n.second){
                    return {};
                }
                fre[target]-=n.second;
                for(int i=0;i<n.second; i++)
                    ret.push_back(n.first);
                if(fre[target]==0)
                    fre.erase(target);
                fre.erase(n.first);
            }
        }
        return ret;
    }
};
