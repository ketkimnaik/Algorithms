class Solution:
    def isPalindrome(self, x: int) -> bool:
        
        w=x
        rev=0
        while(w!=0):
            rev=rev*10+(w%10)
            w=int(w/10)
            
           
        if rev==x:
            return True
        else:
            return False