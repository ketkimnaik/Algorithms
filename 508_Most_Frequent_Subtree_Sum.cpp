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
    unordered_map<int,int> m;
    int max_val=0;
public:
    int Helper(TreeNode* root)
    {
        if(!root)
            return 0;
        
        
        //Helper(root->left,sum);
        int l=Helper(root->left);
        int r=Helper(root->right);
        
        
        m[l+r+root->val]++;
        max_val=max(max_val,m[l+r+root->val]);
        return (l+r+root->val);
        
        
    }
    vector<int> findFrequentTreeSum(TreeNode* root) {
        
        Helper(root);
        
        vector<int> result{};
        
       
        /*for(auto it=m.begin();it !=m.end();++it)
        {
            max_val=max(max_val,it->second);
        }*/
        
        for(auto it=m.begin();it !=m.end();++it)
        {
            if(it->second==max_val)
                result.push_back(it->first);
        }
        
        return result;
        
    }
};