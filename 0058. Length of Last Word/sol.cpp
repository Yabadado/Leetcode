//Time: O(n)
//Space: O(1)

/*
    從尾端往前找，只會有三種情況
    (1)空白->最尾端的字後的空白
    (2)非空白->最尾端的字
    (3)空白->最尾端的字前的空白

e.g.

    "This is a    example    "
               ^     ^     ^
               (3)  (2)   (1) 

所以當找到字後需要有個標記，區分現在空白是(1)或是(3)

*/

class Solution {
public:
    int lengthOfLastWord(string s) {
        int counter = 0;
        bool findWord = false;
        for(int i=s.size()-1; i>=0; i--){
            
            //case (2)
            if(s[i]!=' '){          
                findWord = true;
                counter++;
            }
            
            //case (1)
            else if(s[i]==' ' && !findWord) 
                continue;
            
            //case (3)
            else                    
                break;
        }
        return counter;
    }
};