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
    vector<double> averageOfLevels(TreeNode* root) {
        vector<double> result{};
        
        if(! root) 
            return result;
        
        queue<TreeNode*> q;
        q.push(root);
        double sum;
        int size = q.size();
        int size_t;
        TreeNode* temp;
        
        while(! q.empty()) {
            sum = 0;
            size_t = size;
            while(size--) {
                temp = q.front();
                if(temp->left)
                    q.push(temp->left);
                
                if(temp->right)
                    q.push(temp->right);
                q.pop();
                sum += temp->val;
            }
            
            result.push_back(sum / size_t);
            size = q.size();
            
        }
        
        return result;
    }
};