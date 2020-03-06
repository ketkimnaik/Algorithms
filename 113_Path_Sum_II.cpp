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
    
private:
    vector<vector<int>> resultVec;
    
    void hasPathSum(TreeNode* root, int currentSum, int sum, vector<int>& vec) {
        
        vec.push_back(root->val);  // Push value into vec
        
        if (currentSum + root->val == sum && !root->left && !root->right) { // root to leaf condition
            resultVec.push_back(vec);
            vec.pop_back(); // Make sure this is here, if we enter this, we circumvent
            return; // the pop back below, as we return immediately.
        }

        if (root->left) hasPathSum(root->left, currentSum + root->val, sum, vec); // If it has a left root, recurse into it
        if (root->right) hasPathSum(root->right, currentSum + root->val, sum, vec); // Same for right
        vec.pop_back(); // If there was no successful path, remove the value you've added as you unwind
        return;
    }
    
public:
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        if (!root) return resultVec;
        vector<int> singleIteration;
        hasPathSum(root, 0, sum, singleIteration);
        return resultVec;
    }
};