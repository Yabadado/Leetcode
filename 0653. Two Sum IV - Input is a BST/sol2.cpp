class Solution {
public:
    void inorder(TreeNode* root, vector<int> &s){
        if(!root)
            return;
        inorder(root->left, s);
        s.push_back(root->val);
        inorder(root->right, s);
    }
    bool findTarget(TreeNode* root, int k) {
        vector<int> s;
        inorder(root , s);
        int l = 0, r = s.size()-1;
        
        while(l<r){
            int num = s[l] + s[r];
            if(num == k){
                return true;
            }
            else if(num > k){
                r--;
            }
            else{
                l++;
            }
        }
        return false;
        
    }
    
};
