# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def swapPairs(self, head: ListNode) -> ListNode:
        p=dummy=ListNode(None)
        
        while head and head.next:
            head_next=head.next.next
            p.next=head.next
            
            head.next.next=head
            
            p=head
           
            head=head_next
            
            
        
        p.next=head
        
        
        return dummy.next
        