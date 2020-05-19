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
	TreeNode* searchBST(TreeNode* root, int val) {
		if(not root) return NULL;
		if(root->val==val) return root;
		root->left=searchBST(root->left,val);
		root->right=searchBST(root->right,val);
		if(root->left) return root->left;
		else if(root->right) return root->right;
		return NULL;

	}
};

Brute Force:

class Solution {
public:
    void Search(TreeNode* &root,int value,TreeNode* &res)
    {
        if(!root)
            return ;
        
        
        
        Search(root->left,value,res);
        Search(root->right,value,res);
        
        if(root->val==value)
        {
            res=root;
        }
        
        
    }
    TreeNode* searchBST(TreeNode* root, int val) {
        
        TreeNode* res=NULL;
        Search(root,val,res);
        
        return res;
        
    }
};