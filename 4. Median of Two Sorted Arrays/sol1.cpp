class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int total = nums1.size()+nums2.size();
        int p1 = 0, p2 = 0;
        int cur = 0;
        double ans = 0;
        int cnt = total%2==0 ? total/2+1 : (total+1)/2 ;
        while(1){            
            if(p1+p2 == cnt)
                break;   
            cur = ans;
            if(p1 < nums1.size() && p2 < nums2.size()){
                if(nums1[p1] < nums2[p2]){
                    ans = nums1[p1];
                    p1++;
                    //cout<<"1"<<endl;
                }
                else{
                    ans = nums2[p2];
                    p2++;
                    //cout<<"2"<<endl;
                }
            }
            else{
                if(p1 >= nums1.size() ){
                    ans = nums2[p2];
                    p2++;
                    //cout<<"3"<<endl;
                }
                else{
                    ans = nums1[p1];
                    p1++;
                    //cout<<"4"<<endl;
                }
            } 
        }
        
        if(total%2 ==0)
            return (ans+cur)/2;
        else
            return ans;
    }
};