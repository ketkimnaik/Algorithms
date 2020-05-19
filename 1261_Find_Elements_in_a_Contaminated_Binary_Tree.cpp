/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class FindElements {
    bitset< (2<<20) > vv;
    
    void recover(TreeNode* n, int ii) {
        if(!n) { return; }
        
        vv[ii] = true;
        recover(n->left, ii*2+1);
        recover(n->right, ii*2+2);
    }
public:
    FindElements(TreeNode* root) {
        recover(root, 0);
    }
    
    bool find(int target) {
        return vv[target];
    }
};

/**
 * Your FindElements object will be instantiated and called as such:
 * FindElements* obj = new FindElements(root);
 * bool param_1 = obj->find(target);
 */
 
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
class FindElements {
   vector<int> result{0};
public:
    void preorder(TreeNode* root)
    {
        if(!root)
            return;
       if(root->left)
       {
           root->left->val=2*root->val+1;
           result.push_back(root->left->val);
           preorder(root->left);
       }
        
        if(root->right)
        {
            root->right->val=2*root->val+2;
            result.push_back(root->right->val);
            preorder(root->right);
        }
    }
    FindElements(TreeNode* root) {
        
        root->val=0;
        preorder(root);
        
        
    }
    
    bool find(int target) {
        
        for(int i=0;i<result.size();++i)
        {
            if(target==result[i])
              
                return true;
            
        }
        return false;
    }
};

/**
 * Your FindElements object will be instantiated and called as such:
 * FindElements* obj = new FindElements(root);
 * bool param_1 = obj->find(target);
 */