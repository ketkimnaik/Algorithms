/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    int height(TreeNode* root)
    {
        if(!root)
            return 0;
        int  r=1+max(height(root->left),height(root->right));
        
        return r;
    }
    
    bool isBalanced(TreeNode* root) {
        if(!root)
            return true;
        
        return (isBalanced(root->left) && isBalanced(root->right) && (abs(height(root->left)-height(root->right))<=1));
        
        
    }
};