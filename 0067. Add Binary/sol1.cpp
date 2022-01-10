class Solution {
public:
    string addBinary(string a, string b) {
        
        int len_a = a.size(), len_b = b.size();
        
        int len = max(len_a, len_b);
        a.insert(0, string(len-len_a, '0'));
        b.insert(0, string(len-len_b, '0'));
        len_a = a.size();
        len_b = b.size();
        
        int i=len_a-1 , j = len_b-1 , carry = 0;
        
        while(i>=0 && j>=0){
            
            int num = (a[i]-'0') + (b[j]-'0') + carry;
            carry = num/2;
            num = num%2;
            a[i] = (num+'0');
            
            i--;
            j--;
            
        }
        if(carry)
            a.insert(0, "1");
        
        return a;
    }
};
