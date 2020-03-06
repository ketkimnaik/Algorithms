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
    void flatten(TreeNode* root) {
      // TreeNode *temp=root;
        
        while(root)
        {
            if(root->left)
            {
                TreeNode *temp1=root->left;
                while(temp1->right)
                    temp1=temp1->right;
                temp1->right=root->right;
                root->right=root->left;
                root->left=nullptr;
                
            }
            
            root=root->right;
        }
           
           
           
           
           
               
    }
};