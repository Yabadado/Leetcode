#define ll long long
class Solution {
public:
    string fractionToDecimal(int numerator, int denominator) {
        
        string ans ="";
        unordered_map<ll, int> history;
        
        if( (numerator>0&&denominator<0) || (numerator<0&&denominator>0) )
            ans+="-";
        
        ll num  = numerator;
        
        ans += to_string(llabs(num/denominator));
        
        history[num] = ans.size()+1;  // ans(商) + '.''
        num = (num % denominator)*10;
        
        if(num!=0){
            ans+=".";
        }

        
        //小數部分
        
        while(num){
            
            ans+=to_string(llabs(num/denominator));
            num = num % denominator;
            
            if(history.find(num)!=history.end()){
                ans.insert(history[num], "(");
                ans+=")";
                break;
            }
            history[num] = ans.length();
            num*=10;
        }
        return ans;
    }
};
