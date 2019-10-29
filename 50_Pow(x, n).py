class Solution:
    def myPow(self, x: float, n: int) -> float:
        a=1
        if x>=pow(2,-31) and x<=(pow(2,31)-1):
            if n>0:
                for i in range(n):
                    a=a*x
                return a
            else:
                for i in range(abs(n)):
                    a=a*x
                    
                ans=1/a
                return ans
                
                
            
                
            
                
        else:
            return 0
        
        
            
        