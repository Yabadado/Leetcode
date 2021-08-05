class Solution {
public:
    bool isValid(string s) {
        stack<int> st;
        
        if(s.size()==1) return false;
        
        for(int i=0;i<s.size(); i++){    
            
            if(s[i]==')' && !st.empty() && st.top()=='(')
                st.pop();
            else if(s[i]==']' && !st.empty() && st.top()=='[')
                st.pop();
            else if(s[i]=='}' && !st.empty() && st.top()=='{')
                st.pop();
            else
                st.push(s[i]);
        }
        
        return st.size()==0 ? true : false;
        
    }
};