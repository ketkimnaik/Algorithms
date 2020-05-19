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
    TreeNode* postorder(TreeNode* &root, vector<TreeNode*> &result,vector<int> &to_delete)
    {
        if(!root)
            return NULL;
        
        root->left=postorder(root->left,result,to_delete);
        root->right=postorder(root->right,result,to_delete);
        
        if(find(to_delete.begin(),to_delete.end(),root->val)!=to_delete.end())
        {
            if(root->left)
            result.push_back(root->left);
            
            if(root->right)
                result.push_back(root->right);
            return NULL;
        }
        return root;
            
    }
    
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        
        vector<TreeNode*> result{};
        
        
        
        postorder(root,result,to_delete);
        
        // vector<TreeNode*> forest{};
        
        if(find(to_delete.begin(),to_delete.end(),root->val) ==to_delete.end())
            result.push_back(root);
        
        
        
        
        
        
        return result;
        
    }
};