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
    int in, pre, size;
    
    TreeNode* Helper(vector<int>& preorder, vector<int>& inorder, int stop) {
        if(pre >= size) return nullptr;
        
        if(inorder[in] == stop) {
            in++;
            return nullptr;
        }
        
        TreeNode* root = new TreeNode(preorder[pre++]);
        root->left = Helper(preorder, inorder, root->val);
        root->right = Helper(preorder, inorder, stop);
        
        return root;
    }
        
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        
        in = 0;
        pre = 0;
        size = inorder.size();
        
        return Helper(preorder, inorder, INT_MIN);
    }
};