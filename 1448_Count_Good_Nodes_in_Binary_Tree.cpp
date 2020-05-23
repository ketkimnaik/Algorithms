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
    int ans=0;
    int helper(TreeNode* root,int max_val)
    {
        
        if(!root)
            return 0;
        if(root->val>=max_val)
            ans++;
        if(root->val>max_val)
            max_val=root->val;
        
        helper(root->left,max_val);
        helper(root->right,max_val);
        
        return ans;
    }
    
    int goodNodes(TreeNode* root) {
        
        return helper(root,root->val);
        
    }
};