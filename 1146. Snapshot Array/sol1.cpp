class SnapshotArray {
public:
    SnapshotArray(int length) {
        for(int i=0; i<length; i++){
            map<int,int> mp;
            mp[0] = 0;
            snap_mp[i] = mp;
        }
        snap_cnt = 0;
    }
    
    void set(int index, int val) {
        snap_mp[index][snap_cnt] = val;
    }
    
    int snap() {
        return snap_cnt++;
    }
    
    int get(int index, int snap_id) {
        auto it = snap_mp[index].upper_bound(snap_id);//因為有可能在set前snap，所以找upper_bound的前一個(因值相同會往後)
        it--;
        return it->second;
    }
private:
    unordered_map<int, map<int, int>>snap_mp;
    int snap_cnt;
};


/**
 * Your SnapshotArray object will be instantiated and called as such:
 * SnapshotArray* obj = new SnapshotArray(length);
 * obj->set(index,val);
 * int param_2 = obj->snap();
 * int param_3 = obj->get(index,snap_id);
 */

/*
vector? hash table?
do snap -> update hash table

改成以map紀錄更改
    因為一開始用vector寫法會遇到尚未set就snap->變成要掃過整個array
最後再搜尋map中snap_id的位置。

*/