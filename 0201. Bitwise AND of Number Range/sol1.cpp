/*
從頭開始找，找到最大的區間，再把找到的數位移補正 

*/ 


class Solution {
public
    int rangeBitwiseAnd(int left, int right) {
        int range = int(left&right);
        int mask = INT_MAX;
        int ans = 0, cnt = 0;
        while(left && right){
            int m = left&mask;
            int n = right&mask;
            if(m==n){
                ans=m;
                break;
            }
            left = left1;
            right = right1;
            cnt++;
        }
        return anscnt;
    }
};
