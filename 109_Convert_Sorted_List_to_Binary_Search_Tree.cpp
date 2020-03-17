/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
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
    ListNode *temp;
    TreeNode* inorder(int left,int right)
    {
        if(left>right)
            return NULL;
        else if(left == right)
        {
            TreeNode* root=new TreeNode(temp->val);
            temp=temp->next;
            return root;
        }
        
        int mid=left+(right-left)/2;
        
        TreeNode *root=new TreeNode(0);
        root->left=inorder(left,mid-1);
        root->val=temp->val;
        temp=temp->next;
        root->right=inorder(mid+1,right);
        
        return root;
    }
    
    int count(ListNode* head)
    {
        int cou=0;
        while(head)
        {
            cou++;
            head=head->next;
        }
        return cou;
    }
    
    
public:
    TreeNode* sortedListToBST(ListNode* head) {
        
      // temp=head;
       int c=count(head);
       
       
      temp=head;
        
        
        return inorder(0,c-1);
    }
};