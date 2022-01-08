class Solution {
public:
    
    void getTotal(unordered_map<int, Employee*> &mp, int root, int &sum){
        
        sum += mp[root]->importance;
        for(auto id: mp[root]->subordinates){
            getTotal(mp, id, sum);
        }
    }
    
    int getImportance(vector<Employee*> employees, int id) {
        unordered_map<int, Employee*> importance;
        for(auto employee: employees){
            importance[employee->id] = employee;
        }
        int ret = 0;
        getTotal(importance, id, ret) ;
        return ret;
    }
};
