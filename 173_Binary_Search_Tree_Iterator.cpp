/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class BSTIterator {
    TreeNode *temp;
    queue<int> q;
public:
    BSTIterator(TreeNode* root) {
        temp=root;
       inorder(temp);
        
    }
    
    void inorder(TreeNode *r)
    {
        if(!r)
            return;
        if (r->left )
            inorder(r->left);
        q.emplace(r->val);
        
        
        if (r->right)
            inorder(r->right);
            
        
    }
    
    /** @return the next smallest number */
    int next() {
        int a=q.front();
        q.pop();
        return a;
            
        
    }
    
    /** @return whether we have a next smallest number */
    bool hasNext() {
        if(!q.empty())
            return true;
        else
            return false;
        
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */