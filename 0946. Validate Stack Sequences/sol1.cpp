class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        int push_ptr = 0, pop_ptr = 0;
        stack<int> s;
        
        while(push_ptr < pushed.size()){
            s.push(pushed[push_ptr]);
            //cout<<"push "<<s.top()<<endl;
            while(!s.empty() && s.top()==popped[pop_ptr]){
                //cout<<"pop "<<s.top()<<endl;
                s.pop();
                pop_ptr++;
            }
            push_ptr++;
        }
        
        if(pop_ptr < popped.size()) 
            return 0;
        return 1;
    }
};
/*
pushed = [1,2,3,4,5]
popped = [4,5,3,2,1]
->確認是否能依popped順序pop

1. 直到pop_ptr前一直push
2. pop到stack.top()!=pop_ptr
持續1、2直到push完
如果沒有pop完則為非法順序，反之則合法
*/