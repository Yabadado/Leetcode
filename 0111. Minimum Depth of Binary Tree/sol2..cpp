//Time: O(n)
//Space: O(1)
//DFS->找到該節點下最短路徑+1
class Solution {
public:
    
    int minDepth(TreeNode* root) {
        if(!root)       //root為null才有的情況
            return 0;
        if(!root->left && !root->right) //left
            return 1;
        if(!root->left)                 //沒有左節點->Depth=右節點找到最小之結果
            return minDepth(root->right)+1;
        if(!root->right)                //沒有右節點->Depth=右節點找到最小之結果
            return minDepth(root->left)+1;
        
        return min(minDepth(root->left),minDepth(root->right))+1;   //正常case->找左右子樹最短路徑
    }
};