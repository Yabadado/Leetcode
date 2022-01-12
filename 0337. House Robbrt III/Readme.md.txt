## Question: https://leetcode.com/problems/house-robber-iii/

#### sol1.cpp
20:02~20:30
以buttom-up回來，並只紀錄前面節點的最大值，但要記錄包含該節點(有搶)，不包含該節點(沒搶)
帶入下次遞迴。
* Runtime: 16 ms, faster than 63.68% of C++ online submissions for House Robber III.
* Memory Usage: 22.2 MB, less than 89.41% of C++ online submissions for House Robber III.