optimized solution:


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
    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
        vector<int> res, res1, res2;
        inorder(root1, res1);
        inorder(root2, res2);
        int m = res1.size();
        int n = res2.size();
        res1.resize(m+n);
        
        int i1 = m - 1, i2 = n - 1, icur = m + n -1;
        while(i1 >= 0 && i2 >= 0){
            res1[icur--] = res1[i1] > res2[i2] ? res1[i1--] : res2[i2--];
        }
        while(i2 >= 0)
            res1[icur--] = res2[i2--];
        return res1;
    }
    
private:
    void inorder(TreeNode* root, vector<int>& res){
        if(!root) return;
        inorder(root->left, res);
        res.push_back(root->val);
        inorder(root->right, res);
    }   
};

Brute force:

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
    vector<int> a{};
    
public:
    void inorder(TreeNode* root)
    {
        if(!root)
            return;
        inorder(root->left);
        a.push_back(root->val);
        inorder(root->right);
            
    }
    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
        
        inorder(root1);
        inorder(root2);
        
        sort(a.begin(),a.end());
        
        return a;
        
    }
};