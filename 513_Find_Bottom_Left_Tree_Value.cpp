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
    void Helper(TreeNode* root, vector<int> &ans, int level) {
        if(! root) return;
        
        if(level == 0) {
            ans.push_back(root->val);
        }
        
        Helper(root->left, ans, level - 1);
        Helper(root->right, ans, level - 1);
    }
    
    int height(TreeNode* root) {
        if(! root) return 0;
        
        return 1 + max(height(root->left), height(root->right));
    }
    
    int findBottomLeftValue(TreeNode* root) {
        
        int h = max(height(root->left), height(root->right)) + 1;
        
        vector<int> ans{};
        
        Helper(root, ans, h - 1);
        
        return ans[0];
        
    }
};