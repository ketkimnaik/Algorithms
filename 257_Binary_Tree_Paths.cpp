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
    void preorder(TreeNode* &root, string path, vector<string> &result){
        if(!root)
            return;
        path = path + to_string(root->val);
        if(root->left == NULL && root->right == NULL){
            result.push_back(path);
            /*if(path != "")
                path.pop_back();*/
            return;
        }
        
        preorder(root->left,path + "->",result);
        preorder(root->right,path + "->",result);
    }
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> result{};
        string path = "";
        preorder(root, path, result);
        return result;
    }
};