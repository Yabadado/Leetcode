class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        int push_ptr = 0, pop_ptr = 0;
        int n = pushed.size();
        stack<int> st;
        
        while(push_ptr<n){
            st.push(pushed[push_ptr]);
            while(!st.empty() && st.top()==popped[pop_ptr]){
                st.pop();
                pop_ptr++;
            }
            push_ptr++;
        }
        
        return pop_ptr < n ? false : true;
    }
};
