class Solution:
    def romanToInt(self, s: str) -> int:
        si={"M":1000,"D":500,"C":100,"L":50,"X":10,"V":5,"I":1}
        d={"CM":900,"CD":400,"XC":90,"XL":50,"IX":9,"IV":4}
        
        integer=0
        i=0
        
        while i<len(s):
            if i<len(s)-1 and  s[i:(i+2)] in d:
                integer=integer+d[s[i:(i+2)]]
                i=i+2
            else:
                if s[i] in si:
                    integer=integer+si[s[i]]
        return integer
                
            
        
            
                
        
        
            
            
                
                    
        
                    
                
                
    
        