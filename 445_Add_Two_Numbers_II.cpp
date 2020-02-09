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
    int add(ListNode* t1,ListNode* t2,int count1,int count2,ListNode* &temp )
    {
        if(count1==0 && count2==0)
            return 0;
        
        int carry;
        int val1=0;int val2=0;
        if(count1>count2)
        {
            carry=add(t1->next,t2,count1-1,count2,temp);
            val1=t1->val;
        }
        else if(count1<count2)
        {
             carry=add(t1,t2->next,count1,count2-1,temp);
            val2=t2->val;
        }
        else{
            carry=add(t1->next,t2->next,count1-1,count2-1,temp);
            val2=t2->val;
            val1=t1->val;
        }
        
        int result=val1+val2+carry;
        ListNode* newnode=new ListNode(result%10);
        newnode->next=temp;
        temp=newnode;
        
        return result/10;
        
        
    }
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        
        ListNode* temp;
        int count1=0,count2=0;
        temp=l1;
        while(temp)
        {
            temp=temp->next;
            count1++;
        }
        
        temp=l2;
        
        while(temp)
        {
            temp=temp->next;
            count2++;
        }
        
        temp=NULL;
        
        int carry=add(l1,l2,count1,count2,temp);
        
        if(carry)
        {
            ListNode* newnode=new ListNode(carry%10);
        newnode->next=temp;
        temp=newnode;
            
        }
          
        return temp;
            
        
    }
};