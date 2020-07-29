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
    int diff;
    
    void DFS(TreeNode* root, int max, int min) {
        
        if(! root) return;
        
        if(root->val > max) {
            max = root->val;
        }
        
        if(root->val < min) {
            min = root->val;
        }
        
        if(max - min > diff) {
            diff = max -min;
        }
        
        DFS(root->left, max, min);
        DFS(root->right, max, min);
    }
    
    int maxAncestorDiff(TreeNode* root) {
        
        diff = 0;
        
        DFS(root, 0, 100001);
        
        return diff;
    }
};