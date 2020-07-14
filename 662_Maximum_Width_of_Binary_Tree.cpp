DFS one test case doen not pass:

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
    int DFS(TreeNode* root, int id, int level, vector<int> &leftmostnodeid) {
        if(! root) return 0;
        
        if(level == leftmostnodeid.size()) {
            leftmostnodeid.push_back(id);
        }
        
        return max(id - leftmostnodeid[level] + 1, 
                    max(DFS(root->left, 2 * id + 1, level + 1, leftmostnodeid) ,
                        DFS(root->right, 2 * id + 2, level + 1, leftmostnodeid)));
    }
    
    int widthOfBinaryTree(TreeNode* root) {
        vector<int> leftmostnodeid{};
        return DFS(root, 1, 0, leftmostnodeid);
    }
};

BFS:


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
    
    int widthOfBinaryTree(TreeNode* root) {
        if(! root) return 0;
        
        deque<TreeNode*> q;
        q.push_back(root);
        int size = 0;
        TreeNode* temp;
        int ans = 0;
        
        while(! q.empty()) {
            
            size = q.size();
            ans = max(ans, size);
            
            while(size-- > 0) {
                temp = q.front();
                q.pop_front();
                if(temp == NULL) {
                    q.push_back(NULL);
                    q.push_back(NULL);
                } else {
                    q.push_back(temp->left);
                    q.push_back(temp->right);
                }
            }
            
            while(! q.empty() && q.front() == NULL) {
                q.pop_front();
            }
            
            while(! q.empty() && q.back() == NULL) {
                q.pop_back();
            }
        }
        
        return ans;
    }
};