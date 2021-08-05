#include<cstdio>

class Solution {
public:
    int p;
    int q(int l, int r, int m) {
	    int a = 0;
	    for (int i = ~(l | m | r)&p; i; i -= i & -i)
		    a += q((l | i & -i) * 2, (r | i & -i) / 2, m | i & -i);
	    return p ^ m  ? a : 1;
    }
    int totalNQueens(int n) {
        p=(1<<n)-1;
        return q(0,0,0);
    }
};