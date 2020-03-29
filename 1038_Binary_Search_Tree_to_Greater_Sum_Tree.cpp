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
    TreeNode* bstToGst(TreeNode* root) {
        
        TreeNode* ind=root;
        int sum=0;
        stack<TreeNode*> s;
        while(1)
        {
            while(ind)
            {
                s.push(ind);
                ind=ind->right;
            }
            
            if(s.empty())
                break;
            ind=s.top();
            s.pop();
            sum+=ind->val;
            ind->val=sum;
            ind=ind->left;
        }
        
        return root;
    }
};