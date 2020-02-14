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
    
    vector<TreeNode*> generateTrees(int n) {
        if(n==0)
            return {};
        
        
        vector<vector<vector<TreeNode*>>> dp=vector(n+1,vector(n+1,vector<TreeNode*>(0)));
        
        for(int i=1;i<=n;i++)
            dp[i][i].push_back(new TreeNode(i));
        
        for(int k=2;k<=n;k++)
        
            for(int i=1,j=k;i<=n,j<=n;i++,j++)
            {
                for(int a=i;a<=j;a++)
                {
                    vector<TreeNode*> node1=a-1>=i?dp[i][a-1]:vector<TreeNode*>({NULL});
                    vector<TreeNode*> node2=a+1<=j?dp[a+1][j]:vector<TreeNode*>({NULL});
                    
                    for(auto n1:node1)
                    
                        for(auto n2:node2)
                        {
                            TreeNode* temp=new TreeNode(a);
                            temp->left=n1;
                            temp->right=n2;
                            dp[i][j].push_back(temp);
                        }
                    
                    
                }
            }
        
        return dp[1][n];
    }
};