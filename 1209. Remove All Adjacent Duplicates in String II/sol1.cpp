class Solution {
public:
    string removeDuplicates(string s, int k) {
        stack<string> word;
        for(int i=0; i<s.size(); i++){
            if(!word.empty() && s[i]==word.top().back()){
                string new_w = word.top() + s[i];
                word.pop();
                if(new_w.size()!=k){
                    word.push(new_w);
                }
            }
            else{
                string new_w(1,s[i]);
                word.push(new_w);
            }
        }
        
        string ret = "";
        while(!word.empty()){
            ret += word.top();
            word.pop();
        }
        reverse(ret.begin(), ret.end());
        return ret;
    }
};
