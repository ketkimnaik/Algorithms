class Solution:
    def reverse(self, x: int) -> int:
        p=x
        if p<
0:
            p*=-1
            
        s=str(x)
        rev=s[::-1]
        
        out=int(rev)
        if x<0:
            out*=-1
            
        return(out)