class Solution:
    def lengthOfLastWord(self, s: str) -> int:
        
        
        j=0
        k=0
        s=s.strip() # remove all blank spaces from leading and trailing places
        l=len(s)
        i=l-1
        if not s: # if string id blank return 0
            return 0
        
        for a in s: #check what does string contains more than one words or just on word
            if a==' ': # more than one word
                k=1
                break
            elif a!=' ' and l>0: #just one word
                b=1
        
        if k==1:# calcule length of last word for more than word 
            while s[i]!=' ':
                j+=1
                i-=1
            return j
        elif b==1: # return the length if only one word is there
            return l
        else:
            return 0
                
            
           
        
            
        
       
       
            
        