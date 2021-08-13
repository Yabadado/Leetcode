class Solution {
public:
    bool isAdditiveNumber(string num) {
        int n = num.size();
        for(int i=1; i<n; i++){
            for(int j=i+1; j<n; j++){
                //如果首兩個數中有人超過整個字串的一半->不可能符合條件(不會有第三個數)
                if(max(i, j-i) <= n/2){
                    string num1 = num.substr(0,i);
                    string num2 = num.substr(i,j-i);

                    string sum="";
                    if( (num1.size()>1 && num1[0]=='0') || (num2.size()>1 && num2[0]=='0'))
                        continue;

                    int len = j; 
                    bool valid = true; 
                    
                    //檢查後面的數
                    while(len < n){
                        valid = true;
                        sum = to_string(stoull(num1) + stoull(num2) );
                        if(len + sum.size() > n){
                            valid = false;
                            break;
                        }

                        int length;
                        if(sum=="0")
                            length = 1;
                        else
                            length = (int)(log10(stoull(sum))+1);

                        if(sum != num.substr(len, length)){
                            valid = false;
                            break;
                        }
                        if(valid){
                            num1 = num2;
                            num2 = sum;
                            len += sum.size();
                        }
                        else
                            break;            
                    }
                    //如果跑完剩餘的組合都符合條件
                    if(valid)
                        return true;          
                }  
            }
        }
        return false;
    }
};