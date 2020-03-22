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
   // In pair, returning take this value and not taking connected values or not taking this value and taking connected values.
int rob(TreeNode* root) {
	return robMax(root).first;
}

pair<int, int> robMax(TreeNode* root){
	if(!root) return {0, 0};

	
    	pair<int, int> right = robMax(root->right);
pair<int, int> left = robMax(root->left);
    
	return {max(root->val + right.second + left.second, right.first + left.first), right.first + left.first};
}
};

Using DFS:
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
   
unordered_map<TreeNode*, int>m;

int func(TreeNode* root) {
    
    if(!root) return 0;
    
    int child=0, grandchild=0;
    
    child = func(root->left);
    child += func(root->right);
    
    if(root->left)
    {
        grandchild = m[root->left->left];
        grandchild += m[root->left->right];
    }
    if(root->right)
    {
        grandchild += m[root->right->left];
        grandchild += m[root->right->right];
    }    
    
    m[root] = max(root->val + grandchild , child);    
    return m[root];        
}

int rob(TreeNode* root) {
    
    m.clear();
    if(!root)
        return 0;
    
    return func(root);
}
};