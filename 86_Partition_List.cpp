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
ListNode* partition(ListNode* head, int x) {
    
    if(!head)
        return NULL;
    ListNode* p1=new ListNode(INT_MIN);
    p1->next=head;
    head=p1;
    ListNode *p2=head,*p3=head;
    
    // find the first large value
    
    while(p3 && p3->val<x)
        p3=p3->next;
    
    // if no values are greater than given val then directly return the list as it is
    if(!p3)
        return head->next;
    
    
    while(p2->next !=p3)
        p2=p2->next;
    p1=p3 ;//start traversal if p1 from first large value
    
        
        while(p1->next)
        {
            if((p1->next)->val<x)
            {
             p2->next=p1->next;
                p1->next=p1->next->next;
                p2->next->next=p3;
                p2=p2->next;
            }
            else
            {
                p1=p1->next;
            }
        }
    
    return head->next;
}
};