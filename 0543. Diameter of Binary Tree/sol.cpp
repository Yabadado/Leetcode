class Solution {
public:
    
    //回傳左右邊最長的路徑
    //ans = max(left) + max(right);
    int dis(TreeNode* root, int &cur){
        
        if(!root)
            return 0;

        int left = dis(root->left, cur);        //左子樹最深
        int right = dis(root->right, cur);      //右子樹最深
        int ret = left + right;                 //當前節點最大路徑
        
        if(ret>cur)
            cur = ret;
        
        return max(left, right)+1;
    }
    
    int diameterOfBinaryTree(TreeNode* root) {
        int ans = 0;
        dis(root, ans);
        return ans;
    }
};