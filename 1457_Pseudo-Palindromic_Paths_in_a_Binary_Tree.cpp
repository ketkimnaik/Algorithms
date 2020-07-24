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
    int count;
    vector<int> digit;
    void DFS(TreeNode* root) {
        
        if(! root) return;
        
        digit[root->val]++;
        
        if(root->left == NULL && root->right == NULL) {
            
            int odd_num = 0;
            
            for(int i = 1; i < 10; ++i) {
                if(digit[i] % 2 == 1) odd_num++;
                
                if(odd_num > 1) {
                    digit[root->val]--;
                    return;
                }
            }
            
            count++;
            digit[root->val]--;
            return;
        }
        
        DFS(root->left);
        DFS(root->right);
        digit[root->val]--;
        
    }
    
    int pseudoPalindromicPaths (TreeNode* root) {
        count = 0;
        digit = vector<int> (10, 0);
        
        DFS(root);
        
        return count;
        
    }
};