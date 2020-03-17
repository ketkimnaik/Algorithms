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
    vector<int> rightSideView(TreeNode* root) {
        
        vector<int> result{};
        
        if(!root)
            return result;
        queue<TreeNode*> q;
        q.push(root);
        int level;
        TreeNode *temp;
        while(!q.empty())
        {
            int level=q.size();
            
            
            for(int i=0;i<level;++i)
            {
                temp=q.front();
            q.pop();
                if(i==level-1)
                    result.push_back(temp->val);
            
            
            if(temp->left)
                q.push(temp->left);
            if(temp->right)
                q.push(temp->right);
            }
            
        }
        return result;
    }
};