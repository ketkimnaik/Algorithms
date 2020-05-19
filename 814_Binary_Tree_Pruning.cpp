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
    void DFS(TreeNode* &root)
    {
        if(!root)
            return;
        
        
        
        DFS(root->left);
        
        DFS(root->right);
        if(root->left==nullptr && root->right==nullptr && root->val==0)
        {
            root= nullptr;
            return;
        }
            
    }
    TreeNode* pruneTree(TreeNode* root) {
        
        
        DFS(root);
        
        return root;
        
    }
};