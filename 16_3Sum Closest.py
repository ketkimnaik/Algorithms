class Solution:
    def threeSumClosest(self, s: List[int], target: int) -> int:
        l=len(s)
        op=[]
        for i in range(l-2):
            j=i+1
            while j<(l-1):
                k=j+1
                while k<(l):
                    sum=s[i]+s[j]+s[k]
                    op.append(sum)
                    
                    k=k+1
                j=j+1
        result=[]
        print(op)
        for i in range(len(op)):
            a=target-op[i]
            result.append(a)
        print(result)
        re=[abs(num) for num in result]
        r=0
        for i in range(len(result)):
            if re[i]==min(re):
                r=i
        
        return op[r]
            
            
            
        
       
        