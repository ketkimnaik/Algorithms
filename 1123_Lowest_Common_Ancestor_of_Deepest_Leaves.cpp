/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int getDepth(TreeNode* root) {
        if(! root)   return 0;
        
        int lDepth = 1 + getDepth(root->left);
        int rDepth = 1 + getDepth(root->right);

        return lDepth>rDepth?lDepth:rDepth;
    }

    TreeNode* lcaDeepestLeaves(TreeNode* root) {
        if(! root)   return NULL;

        int lDepth = getDepth(root->left);
        int rDepth = getDepth(root->right);
        
        if(lDepth == rDepth)  return root;
        
        return lDepth > rDepth ? lcaDeepestLeaves(root->left) : lcaDeepestLeaves(root->right);
    }
};