class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        unordered_map<char, char> mp = {
            {')', '('},
            {']', '['},
            {'}', '{'}
        };
        for(auto &c: s){
            if(!st.empty() && st.top() == mp[c]){
                st.pop();
            }
            else{
                st.push(c);
            }
        }
        return st.empty() ? true : false;
    }
};
