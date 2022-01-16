class Solution {
public:
    int minMoves(int target, int maxDoubles) {
        int num = 1;
        int cnt = 0;
        
        if(maxDoubles==0){
            return target-1;
        }
        
        while(target!=1){
            
            if(target%2){
                cnt+=2;
                target = (target-1)/2;
                maxDoubles--;
            }
            else{
                cnt++;
                target = target/2;
                maxDoubles--;
            }
            //cout<<cnt<<" "<<target<<endl;
            if(maxDoubles==0){
                cnt+=target-1;
                break;
            }
        }
        return cnt;
    }
};
