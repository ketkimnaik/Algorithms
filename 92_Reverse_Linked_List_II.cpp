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
ListNode* reverseBetween(ListNode* head, int m, int n) 
{
    if(head == NULL)
        return NULL; 
    
    ListNode *temp, *curr = head, *prev = NULL;
    while(m>1)
    {
        prev = curr;
        curr = curr->next;
        m--;
        n--; 
    }
   
    
    ListNode *temp1 = prev, *temp2 = curr;
    
    
    while(n>0)
    { //for reversal
        temp = curr->next;
        curr->next = prev;
        prev = curr;
        curr = temp;
        n--;
    }
    
    if(temp1!= NULL) 
    {
        temp1->next = prev;
    }
    else
    { //To handle the case if m=0
        head = prev;
    }
    
    temp2->next = curr; 
    return head;
	}
};