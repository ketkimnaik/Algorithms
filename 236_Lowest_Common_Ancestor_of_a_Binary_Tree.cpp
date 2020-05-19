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
    TreeNode* result, *p,*q;
    
    bool Helper(TreeNode* root)
    {
        if(result)// if already result exist then return 
            return false;
        int count=0;
        
        if(root==p )
            count++;
        if(root==q)
            count++;
        
        if(count !=2 && root->left)
        {
            if(Helper(root->left))
                count++;
            
        }
        
        if(count !=2 && root->right)
        {
            if(Helper(root->right))
                count++;
            
        }
        if (result) 
            return false;
        
        if(count==2)
        {
            result=root;
            return false;
        }
        
        return count;
    }
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (!root)
            return nullptr;
        
        if(p)
        {
            if(!q)
                return p;
        }
        
        else if(q)
            return q;
        
        else 
        {
            while(root->left)
                root=root->left;
            return root;
                
        }
        
        
            result=nullptr;
            this->p=p;
            this->q=q;
            Helper(root);
            
       
            
        return result;
    }
};

Solution2:
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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        TreeNode *l = root->left ? lowestCommonAncestor(root->left, p, q) : nullptr;
        TreeNode *r = root->right ? lowestCommonAncestor(root->right, p, q) : nullptr;
        return (root == p or root == q or (l and r)) ? root : l ? l : r;
    }
};