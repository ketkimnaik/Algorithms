/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    int numComponents(ListNode* head, vector<int>& G) {
        ListNode *p = head, *q;
        int c = 0;
        while(p) c++, p = p->next;
        if(c==1 && G.size()==1) return 1;
        if(c==1 && G.size()==0) return 0;
        
        vector<int> l(c,-2);
        for(auto g:G) l[g]=-1;
        p = head, q = head->next;
        
        while(q){
            if(l[p->val]==-1 && l[q->val]==-1) l[p->val]=q->val;
            q = q->next;
            p = p->next;
        }
        int ans = 0;
        for(auto x: l) if(x==-1) ans++;
        return ans;
    }
};