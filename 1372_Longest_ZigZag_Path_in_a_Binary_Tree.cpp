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
    int dfs(TreeNode* root, int cost, int dir) {
        if (root != nullptr) {
            if (dir == -1) {
                return max(dfs(root -> left, 0, 1), dfs(root -> right, 0, 0));
            } else if (dir) {
                return max(dfs(root -> left, 0, 1), dfs(root -> right, cost + 1, 0));
            } else {
                return max(dfs(root -> left, cost + 1, 1), dfs(root -> right, 0, 0));
            }
        } else {
            return cost;
        }
    }
    int longestZigZag(TreeNode* root) {
        return dfs(root, 0, -1);
    }
};