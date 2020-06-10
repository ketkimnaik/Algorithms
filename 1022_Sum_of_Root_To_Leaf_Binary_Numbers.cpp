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
    int sumRootToLeaf(TreeNode* root) {

    return totalSum(root, 0);
	
}

int totalSum(TreeNode* root, int sum){

    if(!root)
        return 0;
		
    sum *= 2;
    sum += root->val;
    
    if(!root->left && !root->right)
        return sum;

    return totalSum(root->left, sum) + totalSum(root->right, sum);      
}
};