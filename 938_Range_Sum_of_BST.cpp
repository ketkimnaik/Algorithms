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
    int sum=0;
    void inorder(TreeNode* root, int L, int R)
    {
        if(root->val>=L && root->val<=R)
        {
            sum+=root->val;
            //cout<<sum<<endl;
        }
        
        if(root->left)
            inorder(root->left,L,R);
        if(root->right)
            inorder(root->right,L,R);
         
    }
    int rangeSumBST(TreeNode* root, int L, int R) {
        
        if(!root)
            return 0;
        
        inorder(root,L,R);
        return sum;
        
    }
};