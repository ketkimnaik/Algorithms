class Solution:
    
    def longestPalindrome(self, s):
        if not s: return s
       

        res = ""
        for i in range(len(s)):
            j = i + 1
            
            while j <= len(s) and len(res) <= len(s[i:]):
                
                if s[i:j] == s[i:j][::-1] and len(s[i:j]) > len(res): #reverse condition and length of result string is check
                    
                    res = s[i:j]
                    
                j += 1

        return res

s=Solution()
print(s.longestPalindrome("abbcd"))
    
    
    
            
             
            
            
            
              
        
       