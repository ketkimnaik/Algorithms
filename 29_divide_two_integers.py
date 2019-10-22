class Solution:
    def divide(self, dividend: int, divisor: int) -> int:
        
        n=0
        k=divisor
        i=0
        j=0
        if divisor<0:
            i=1
            divisor=-1*divisor
        if dividend<0:
            j=1
            dividend=-1*dividend
        
      
        while divisor<=dividend:
            
            
            n=n+1
            divisor=divisor+k
        result=n
        if i==1 or j==1:
            return (result*-1)
        else:
            return result
            
        
        
            