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
    vector<int> largestValues(TreeNode* root) {
        if(!root) return {};
            
        vector<int> result{};
        queue<TreeNode*> q;
        q.push(root);
        int size = 0;
        int level = -1;
        TreeNode* temp;
        
        while(! q.empty()) {
            
            if(size == 0) {
                size = q.size();
                result.push_back(INT_MIN);
                level++;
            }
            
            temp = q.front();
            q.pop();
            size--;
            
            result[level] = max(result[level], temp->val);
            
            if(temp->left) {
                q.push(temp->left);
            }
            if(temp->right) {
                q.push(temp->right);
            }
            
        }
        
        return result;
    }
};