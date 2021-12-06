## Question: https://leetcode.com/problems/snapshot-array/

#### sol1.cpp
用hash table<int, map>去存每個index的改變狀態，query時去找該index snap_id的upper_bound
* Runtime: 8 ms, faster than 52.60% of C++ online submissions for Iterator for Combination.
* Memory Usage: 12.9 MB, less than 12.38% of C++ online submissions for Iterator for Combination.