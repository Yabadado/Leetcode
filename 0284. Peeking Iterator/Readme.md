## Question: https://leetcode.com/problems/peeking-iterator/

#### sol1.cpp
1. 在peek的時候可以先記錄，這樣就不用再找一次
2. `peek()`和`next()` 改念沒問題，但是在`hasNext()`卡關
3. 後來發現是因為忽略題目給的Iterator部分....
* Runtime: 4 ms, faster than 67.30% of C++ online submissions for Peeking Iterator.
* Memory Usage: 7.5 MB, less than 32.23% of C++ online submissions for Peeking Iterator.
