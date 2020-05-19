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
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        return DFS(nums, 0, nums.size());
    }
    
    TreeNode* DFS(vector<int>& nums, int l, int r){
        if(l == r) return NULL;
        int maxPos = l;
        for(int i = l; i < r; i++) if(nums[i] > nums[maxPos]) maxPos = i;
        TreeNode* root = new TreeNode(nums[maxPos]);
        root->left = DFS(nums, l, maxPos);
        root->right = DFS(nums, maxPos + 1, r);
        return root;
    }
};

Using Divide and Conquer:

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
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        auto it=max_element(nums.begin(),nums.end());
        int index=distance(nums.begin(),it);
        
        TreeNode* root=new TreeNode(*it);
        if (nums.size() == 1) return root;
        
        vector<int> lefttree{nums.begin(),nums.begin()+index};
        vector<int> righttree{nums.begin()+index+1,nums.end()};
      
        if(lefttree.size()==0 && righttree.size()==0)
        {
            root->left=NULL;
            root->right=NULL;
            return root;
        }
        else if(lefttree.size()==0 && righttree.size()>0)
        {
            root->left=NULL;
            root->right=constructMaximumBinaryTree(righttree);
        }
        else if(lefttree.size()>0 && righttree.size()==0)
        {
            root->right=NULL;
            root->left=constructMaximumBinaryTree(lefttree);
            
        }
        else
        {
            root->right=constructMaximumBinaryTree(righttree);
            root->left=constructMaximumBinaryTree(lefttree);
            
        }
      
        
        return root;
        
    }
};