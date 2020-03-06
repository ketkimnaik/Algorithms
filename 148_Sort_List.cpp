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
    ListNode* sortList(ListNode* head) {
        
        if(!head || !head->next)
            return head;
        ListNode* l,*m,*r;
        ListNode*lt,*mt,*rt;
        ListNode temp1(0);
        ListNode temp2(0);
            
        l=&temp1;
        r=&temp2;
        m=head;
        
        head=head->next;
        lt=l;
        mt=m;
        rt=r;
        
        while(head)
        {
            if(head->val<m->val)
            {
                lt->next=head;
                head=head->next;
                lt=lt->next;
            }
            else if(head->val>m->val)
            {
                rt->next=head;
                head=head->next;
                rt=rt->next;
            }
            else
            {
               mt->next=head;
                head=head->next;
                mt=mt->next; 
            }
        }
        
        lt->next=nullptr;
        rt->next=nullptr;
        mt->next=nullptr;
        
        
        l=l->next;
        r=r->next;
        
        l=sortList(l);
        r=sortList(r);
        
        if(l)
        {
            head=l;
            lt=l;
            while(lt->next)
                lt=lt->next;
            lt->next=m;
            mt->next=r;
        }
        else
        {
            head=m;
            mt->next=r;
        }
               
        return head;
    }
};