class Solution:
    def strStr(self, haystack: str, needle: str) -> int:
        a=len(haystack)
        b=len(needle)
        new_i=0
        
        for i in range(a):
            if haystack[i]==needle[0]:
                k=i
                for j in range(1,b):
                    k=k+1
                    if haystack[k]==needle[j]:
                        new_i=new_i+1
                        
                    
                result=i
                if new_i==b-1:
                    break
        if new_i==b-1:
            return result
        else:
            return -1
            
                    
        
        