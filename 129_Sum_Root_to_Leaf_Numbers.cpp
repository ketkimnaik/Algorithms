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
    
    void DFS(TreeNode* root,int &ans,int tmp)
    {
        if(!root)
            return;
        int result=10*tmp+root->val;
        
        if(root->left == NULL && root->right==NULL)
            ans+=result;
        
        if(root->left)
            DFS(root->left,ans,result);
        if(root->right)
            DFS(root->right,ans,result);
    }
    int sumNumbers(TreeNode* root) {
        
        if(!root)
            return 0;
        
        int ans=0;
        DFS(root,ans,0);
        
        
        return ans;
        
    }
};