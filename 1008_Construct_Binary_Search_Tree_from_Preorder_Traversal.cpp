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
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        int n=preorder.size();
        
        if(n==0)
            return NULL;
        TreeNode* root=new TreeNode(preorder[0]);
      
        for(int i=1;i<n;++i)
        {
            TreeNode* current=root;
            bool done=false;
            while(done==false)
            {
                if(preorder[i]<current->val)
                {
                    if(current->left)
                        current=current->left;
                    else
                    {
                    current->left=new TreeNode(preorder[i]);
                    
                    done=true;
                    }
                }
                
                else
                {
                   if(current->right)
                        current=current->right;
                    else
                    {
                    current->right=new TreeNode(preorder[i]);
                    
                    done=true;
                    }
                    
                }
            }
        }
        
        return root;
        
    }
};