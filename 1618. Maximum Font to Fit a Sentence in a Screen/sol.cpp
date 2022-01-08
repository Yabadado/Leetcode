class Solution {
public:
    
    int sizeValid(FontInfo &fontInfo, int &w, int &h, int &size, string &s){
        
        if(fontInfo.getHeight(size)>h)
            return false;
        int sum = 0;
        
        for(int i=0; i<s.size(); i++){
            sum += fontInfo.getWidth(size, s[i]);
        }
        if(sum>w)
            return false;
        
        return true;
    }
    
    int maxFont(string text, int w, int h, vector<int>& fonts, FontInfo fontInfo) {
        
        int cur_size = -1;
        
        int left = 0, right = fonts.size()-1;
        while(left<=right){
            int mid = left + (right-left)/2;
            
            if(!sizeValid(fontInfo, w, h, fonts[mid], text)){
                right = mid-1;
            }
            else{
                cur_size = fonts[mid];
                left = mid+1;
            }
        }
        
        if(cur_size == -1 && !sizeValid(fontInfo, w, h, fonts[left], text))
            return -1;
        return cur_size;
    }
};
