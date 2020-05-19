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
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        
        if(!root)
        {
            auto result=new TreeNode(val);
            return result;
        }
        
        if(root->val<val)
            root->right=insertIntoBST(root->right,val);
        else if(root->val>val)
            root->left=insertIntoBST(root->left,val);
        
        return root;
        
        
        
    }
};