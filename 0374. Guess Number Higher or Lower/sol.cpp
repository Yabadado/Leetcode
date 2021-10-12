/*
	��binary-search�h���q�Ʀr�A�i�H�N�����ױqO(n)���C��O(log n) 
	
*/

class Solution {
public:
    int guessNumber(int n) {
        int left = 1, right = n;
        int ans = 0;
        while(left<=right){
            int mid = left + (right-left)/2;
            int getguess = guess(mid);
            if(getguess==-1)
                right = mid-1;
            else if(getguess==1)
                left = mid+1;
            else{
                ans = mid;
                break;
            }
        }
        return ans;
    }
};
