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
   
    TreeNode* helper(vector<int>& inorder, vector<int>& postorder,int istart,int iend, int pstart, int pend) {
        
        if(istart>iend || pstart>pend)
            return NULL;
        
        int a=istart;
        
        int v=postorder[pend];
        
        while(inorder[a] != v)
            a++;
        
        TreeNode *root=new TreeNode(v);
        
        root->left=helper(inorder,postorder,istart,a-1,pstart,pstart+a-1-istart);
        root->right=helper(inorder,postorder,a+1,iend,pend-iend+a ,pend-1);
        
        return root;
        
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        
        int isize=inorder.size();
        int psize=postorder.size();
        if(isize != psize )
            return NULL;
        
        if(isize==0 || psize==0)
            return NULL;
        
        return helper(inorder,postorder,0,isize-1,0,psize-1);
            
        
    }
};