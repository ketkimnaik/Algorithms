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
    int steps ;
public:
    int distributeCoinsHelper(TreeNode* root) {
        if(! root) return 0;
        
        int l = distributeCoinsHelper(root->left);
        steps += abs(l);
        
        int r = distributeCoinsHelper(root->right);
        steps += abs(r);
        
        root->val += l + r;
        
        return root->val - 1;
    }
    int distributeCoins(TreeNode* root) {
        steps = 0;
        distributeCoinsHelper(root);
        return steps;
    }
};