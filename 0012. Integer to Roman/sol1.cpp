class Solution {
public:
    string intToRoman(int num) {
        vector<pair<int, string>> mp={
            {1000, "M"}, {900, "CM"}, {500, "D"}, {400, "CD"}, {100, "C"},
            {90, "XC"}, {50, "L"}, {40, "XL"}, {10, "X"}, {9, "IX"}, {5, "V"}, {4, "IV"}, {1, "I"}
        };
        string ret = "";
        for(auto n :mp){
            while(num >= n.first){
                ret+=n.second;
                num-=n.first;
            }
        }
        return ret;
    }
};
