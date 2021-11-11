## Question: https://leetcode.com/problems/remove-nth-node-from-end-of-list/

sol1.cpp:

* Runtime: 0 ms, faster than 79.14 % of C++ online submissions for Remove Nth Node From End of List.
* Memory Usage: 10.5 MB, less than 96.43% of C++ online submissions for Remove Nth Node From End of List.

1. Find list length
2. edge condition -> list length == 0 or 1 、 remove head
3. loop and record preNode.
4. based case: remove node.

sol2.cpp:

* Runtime: 0 ms, faster than 100.00% of C++ online submissions for Remove Nth Node From End of List.
* Memory Usage: 10.5 MB, less than 96.53% of C++ online submissions for Remove Nth Node From End of List.

1. Use fast and slow ptr to find nth Node from end.
2. edge condition -> list length == 0 or 1 、 remove head
3. based case: remove node.
