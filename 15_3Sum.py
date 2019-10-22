class Solution:
    def threeSum(self, s: List[int]) -> List[List[int]]:
        l=len(s)
        op=[]
        r=[]
        for i in range(l-2):
            j=i+1
            while j<(l-1):
                k=j+1
                while k<(l):
                    if s[i]+s[j]+s[k]==0:
                        a=[s[i],s[j],s[k]]
                        a.sort()
                        print(a)
                        op.append(a)
                        r=op
                    k=k+1
                j=j+1
        result=[]
        for i in r:
            if i not in result:
                result.append(i)
            result.sort()
        return result
                    
                    
                    
                    
                
                
                    
               
        
                
                
            
        
        