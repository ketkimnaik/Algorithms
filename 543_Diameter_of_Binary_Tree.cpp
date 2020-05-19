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
    int diameterOfBinaryTree(TreeNode* root) {
        // Check if tree exists
        if (root == NULL) return 0;
        
        // Find depths of left and right subtrees
        int leftDepth = DFS(root->left);
        int rightDepth = DFS(root->right);
        
        // Return largest diameter (maybe not through root)
        return max(diam, leftDepth + rightDepth);
    }
    
// Good practice to make internal methods and class variables private
private:
    
    // Class variable to save max diameter found
    int diam = 0;
    
    // Recursive DFS method
    int DFS(TreeNode* root) {
        // Check for leaf node
        if (root == NULL) return 0;
        
        // Find depths of left and right subtrees
        int leftDepth = DFS(root->left);
        int rightDepth = DFS(root->right);
        
        // Diameter is the number of edges between the farthest nodes
        diam = max(diam, leftDepth + rightDepth);
        
        // Return the depth of the current subtree
        return max(leftDepth, rightDepth) + 1;
    }
};