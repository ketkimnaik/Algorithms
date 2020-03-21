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
    int count=0;
    
    void Helper(TreeNode* root)
    {
        if(!root)
            return;
        
        
        
        count++;
        
        
        
            Helper(root->left);
        
            Helper(root->right);
    }
public:
    int countNodes(TreeNode* root) {
        
        Helper(root);
        return count;
    }
};