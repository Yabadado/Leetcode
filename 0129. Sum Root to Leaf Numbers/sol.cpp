class Solution {
public:
    /*
        top-down
        bottom: leaf node -> sum add val;
    */
    
    void getVal(TreeNode* root, int tmp, int &sum){
        
        tmp = tmp*10 + root->val;
        
        if(!root->left && !root->right){
            sum += tmp;
            return;
        }
        
        if(root->left)
            getVal(root->left, tmp, sum);
        if(root->right)
            getVal(root->right, tmp, sum);
    }
    
    int sumNumbers(TreeNode* root) {
        int sum = 0;
        getVal(root, 0, sum);
        return sum;
    }
};
