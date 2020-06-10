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
    void Helper(TreeNode* root, vector<int> &result){
        if(! root)
            return;
        if((! root->left) && (! root->right)){
           result.push_back(root->val);
        }
        
        Helper(root->left, result);
        Helper(root->right, result);
            
    }
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        vector<int> result1{};
        vector<int> result2{};
        
        Helper(root1, result1);
        Helper(root2, result2);
        
        return result1 == result2;
    }
};