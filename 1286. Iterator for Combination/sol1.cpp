class CombinationIterator {
public:
    CombinationIterator(string characters, int combinationLength) {
        
        maxlen = combinationLength;
        initcomb(characters, "", 0);
        
    }
    
    string next() {
        return comb[next_idx++];
    }
    
    bool hasNext() {
        return next_idx<comb.size();
    }
    
    void initcomb(string characters, string cur, int idx){
        
        if(idx > characters.size())
            return;
        
        if(cur.size()==maxlen){
            comb.push_back(cur);
            return;
        }
        
        for(int i=idx; i<characters.size(); i++){
            string tmp = cur;
            cur += characters[i];
            initcomb(characters, cur, i+1);
            cur = tmp;
        }
        
    }
    vector<string> comb;
    int maxlen = 0;
    int next_idx = 0;
};