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
        vector<int> distanceK(TreeNode* root, TreeNode* target, int K) {
        
            vector<int> ret;
            inorder(root,target,K,ret);
            return ret;
        }
    
        int inorder(TreeNode *root, TreeNode *target, int &K, vector<int> &ret) {
        
            if(!root) return 0;
            
            if(root == target) {
            
                kdistance(target, K, ret);
                K--;
                return 1;
            }
            
            int l = inorder(root->left, target, K, ret);
            
            if(l) {
            
                if(K == 0) {
                
                    ret.push_back(root->val);
                    return 0;
                } else {
                
                    kdistance(root->right, K-1, ret);
                    K--;
                    return 1;
                }
                
            }
            
            int r = inorder(root->right, target, K, ret);
            
            if(r) {
            
                if(K == 0) {

                    ret.push_back(root->val);
                    return 0;
                } else {
                
                    kdistance(root->left, K-1, ret);
                    K--;
                    return 1;
                }
                
            }
            return l && r;
        }
    
        void kdistance(TreeNode *root, int K, vector<int> &ret) {
        
            if(!root) return ;
            
            if(K==0) {
            
            ret.push_back(root->val);
            return;
            }
            
            kdistance(root->left, K-1, ret);
            kdistance(root->right, K-1, ret);
    }
};